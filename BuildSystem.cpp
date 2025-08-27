// BuildSystem.cpp
#include "BuildSystem.h"
#include "game.h"
#include <string>
#include <cstdio>   // std::snprintf
// === ����ʱ�Խ� UI�����ֲ��䣩 ===
extern void BuildUI_OnStartBattlePressed();
extern void BuildUI_SetEnterBattleCallback(void(*)());

#if defined(_WIN32)
#include <Windows.h>
#endif

namespace RTS9 {

    std::string HUDText(const GameState& gs) {
        char buf[256];
        std::snprintf(buf, sizeof(buf),
            "��λ:%d  ���:%d  ħ��ʦ:%d  �ܱ�:%d",
            gs.res.units, gs.res.coins, gs.res.mageUnits, gs.res.shieldUnits);
        return std::string(buf);
    }
    static bool s_battleCountdownLock = false;

    static void EnterBattle_AfterCountdown() {
        s_battleCountdownLock = false;
        SetcurrentScene(GameScene::Battle);
    }

    void InitGame(GameState& gs) { gs = GameState{}; }

    void OpenMenu(GameState& gs, int idx) {
        gs.menuOpen = true;
        gs.menuTileIndex = idx;
        gs.currentMenu = MakeMenuForTile(gs, idx);
        gs.selectedIdx = 0;
    }

    void CloseMenu(GameState& gs) {
        gs.menuOpen = false;
        gs.menuTileIndex = -1;
        gs.currentMenu.clear();
        gs.selectedIdx = 0;
    }

    void OpenBattleConfirm(GameState& gs) {
        gs.menuOpen = true;
        gs.currentMenu.clear();

        MenuEntry start;  start.action = MenuAction::StartBattle; start.text = L"��ʼս��"; start.icon = "battle_start.tga";
        MenuEntry cancel; cancel.action = MenuAction::Cancel;     cancel.text = L"ȡ��";     cancel.icon = "cancel.tga";

        gs.currentMenu.push_back(start);
        gs.currentMenu.push_back(cancel);
        gs.selectedIdx = 0;
    }

    static inline bool IsValid(int i) { return i >= 0 && i < GRID_SIZE; }

    void HandleInput(GameState& gs, const InputState& in)
    {
        // �� ����ʱ�ڼ�ֱ�Ӻ�������
        if (s_battleCountdownLock) {
            return;
        }

        // ���� ����򿪲˵������ֲ��䣩
        if (in.leftClickTileIndex >= 0 && IsValid(in.leftClickTileIndex) && gs.playerStanding[in.leftClickTileIndex]) {
            OpenMenu(gs, in.leftClickTileIndex);
        }

        if (gs.menuOpen && !gs.currentMenu.empty()) {

            // ===== �ؼ�����������ֱ�Ӽ�� Up/Down �ġ����ش����� =====
            bool upTrig = false;
            bool downTrig = false;

            // 1) ���̣�Win32����GetAsyncKeyState �� LSB ��ʾ�����ϴβ�ѯ���������¡�
#if defined(_WIN32)
            upTrig |= ((GetAsyncKeyState(VK_UP) & 0x0001) != 0);
            downTrig |= ((GetAsyncKeyState(VK_DOWN) & 0x0001) != 0);
#endif

            // 2) �ֱ�����ѡ����������� PadTrigger(PAD_UP/DOWN) ֮����ڴ˲���
            // upTrig   |= PadTrigger(PAD_UP);
            // downTrig |= PadTrigger(PAD_DOWN);

            // 3) �������߼������Ҽ��Կ��ã���ֹ�㻹û�ص���ӳ�䣩
            upTrig |= in.leftArrowPressed;   // �ѡ���Ҳ������һ��
            downTrig |= in.rightArrowPressed;  // �ѡ��ҡ�Ҳ������һ��

            if (upTrig) {
                gs.selectedIdx = (gs.selectedIdx - 1 + (int)gs.currentMenu.size()) % (int)gs.currentMenu.size();
            }
            if (downTrig) {
                gs.selectedIdx = (gs.selectedIdx + 1) % (int)gs.currentMenu.size();
            }

            // �ر�
            if (in.closePressed) {
                CloseMenu(gs);
            }

            // ȷ��
            if (in.spacePressed) {
                auto& e = gs.currentMenu[gs.selectedIdx];

                if (e.action == MenuAction::Cancel) { CloseMenu(gs); return; }

                if (e.action == MenuAction::StartBattle) {
                    BuildUI_SetEnterBattleCallback(&EnterBattle_AfterCountdown);
                    BuildUI_OnStartBattlePressed();
                    s_battleCountdownLock = true;
                    return;
                }

                if (!IsValid(gs.menuTileIndex)) { CloseMenu(gs); return; }
                auto& tile = gs.grid[gs.menuTileIndex];

                switch (e.action) {
                case MenuAction::Build_Gold:    PlaceBuilding(gs.res, tile, BuildingType::Gold);        break;
                case MenuAction::Build_Recruit: PlaceBuilding(gs.res, tile, BuildingType::Recruit);     break;
                case MenuAction::Build_Mage:    PlaceBuilding(gs.res, tile, BuildingType::MageHouse);   break;
                case MenuAction::Build_Shield:  PlaceBuilding(gs.res, tile, BuildingType::ShieldHouse); break;
                case MenuAction::Build_Saint:   PlaceBuilding(gs.res, tile, BuildingType::SaintHouse);  break;
                case MenuAction::Upgrade:       UpgradeBuilding(gs.res, tile);                          break;
                case MenuAction::Demolish:
                    DemolishBuilding(gs.res, tile);
                    gs.res.units += 1; // ������� 1 ��λ
                    break;
                case MenuAction::Train:
                    TrainUnit(gs.res, tile);
                    break;
                default: break;
                }

                gs.currentMenu = MakeMenuForTile(gs, gs.menuTileIndex);
                if (gs.selectedIdx >= (int)gs.currentMenu.size()) gs.selectedIdx = 0;
            }
        }
    }

} // namespace RTS9
