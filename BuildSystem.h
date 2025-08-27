#pragma once
#include <array>
#include <vector>
#include <string>

namespace RTS9 {

    // ====== ����ߴ� ======
    constexpr int GRID_W = 3;
    constexpr int GRID_H = 3;
    constexpr int GRID_SIZE = GRID_W * GRID_H;

    // ====== ��Դ�뽨�� ======
    struct Resources {
        int units = 6;
        int coins = 60;
        int mageUnits = 0;
        int shieldUnits = 0;
    };

    enum class BuildingType : int {
        None = 0,
        Gold,
        Recruit,
        MageHouse,
        ShieldHouse,
        SaintHouse
    };

    struct Building { BuildingType type = BuildingType::None; int level = 0; };
    struct Tile { Building b; };

    // ====== �˵����� ======
    enum class MenuAction {
        None = 0,
        Build_Gold,
        Build_Recruit,
        Build_Mage,
        Build_Shield,
        Build_Saint,
        Upgrade,
        Demolish,
        Train,
        StartBattle,
        Cancel,
    };

    struct MenuEntry {
        MenuAction   action = MenuAction::None;
        std::wstring text;
        std::string  icon;
    };

    struct InputState {
        bool upArrowPressed = false;  // �� ����
        bool downArrowPressed = false;  // �� ����
        int  leftClickTileIndex = -1;
        bool leftArrowPressed = false;
        bool rightArrowPressed = false;
        bool spacePressed = false;
        bool closePressed = false;
    };

    struct GameState {
        Resources res;
        std::array<Tile, GRID_SIZE> grid{};
        bool menuOpen = false;
        int  menuTileIndex = -1;
        std::vector<MenuEntry> currentMenu;
        int  selectedIdx = 0;
        std::array<bool, GRID_SIZE> playerStanding{};
    };


    // �� ��ͬ���������ȼ�
    inline int MaxLevelForBuilding(BuildingType t) {
        switch (t) {
        case BuildingType::Gold:
        case BuildingType::Recruit:
            return 3;  // ����ݡ���ļ�ݣ�3���ⶥ
        case BuildingType::MageHouse:
        case BuildingType::ShieldHouse:
        case BuildingType::SaintHouse:
            return 4;  // ������4���ⶥ������������ƣ�
        default:
            return 0;
        }
    }

    // ====== С���ߣ�������======
    // ԭ����1->2=30 ��2->3=50
    inline int UpgradeCoinCost(int lv) {
        // lv ָ����ǰ�ȼ������� lv ���� lv+1 �Ľ�һ���
        if (lv == 1) return 30;
        if (lv == 2) return 50;
        if (lv == 3) return 200;   // �� 3->4
        return 1000000000;
    }
    inline int UpgradeUnitCost(int lv) {
        // ֻ������ 4 ����Ҫ 20 ��λ
        return (lv == 3) ? 20 : 0;
    }

    // ���ݾɵ��ã�ֻҪ��ң�
    inline int UpgradeCost(int lv) { return UpgradeCoinCost(lv); }

    inline int RefundOnDemolish(int lv) { return lv == 1 ? 0 : lv == 2 ? 20 : lv == 3 ? 60 : 0; }
    inline int GoldIncome(int lv) { return lv == 1 ? 10 : lv == 2 ? 20 : lv == 3 ? 40 : 0; }
    inline int RecruitUnits(int lv) { return lv == 1 ? 1 : lv == 2 ? 2 : lv == 3 ? 4 : 0; }

    inline const char* BuildingName(BuildingType t) {
        switch (t) {
        case BuildingType::Gold:        return "�����";
        case BuildingType::Recruit:     return "��ļ��";
        case BuildingType::MageHouse:   return "ħ��ʦ��";
        case BuildingType::ShieldHouse: return "�ܱ���";
        case BuildingType::SaintHouse:  return "ʥŮ��";
        default:                        return "�յ�";
        }
    }

    // ��ͼ����֧�� (b) �� (type, level) ���ֵ���
    inline std::string SpriteForBuilding(BuildingType t, int level) {
        if (level <= 0 || t == BuildingType::None) return "";
        const char* base = "";
        switch (t) {
        case BuildingType::Gold:        base = "gold";  break;
        case BuildingType::Recruit:     base = "human"; break;
        case BuildingType::MageHouse:   base = "magic"; break;
        case BuildingType::ShieldHouse: base = "sheld"; break; // ά����������
        case BuildingType::SaintHouse:  base = "me";    break;
        default: return "";
        }
        std::string fn = std::string(base) + std::to_string(level);
        fn += (t == BuildingType::Recruit ? ".jpg" : ".tga");
        return fn;
    }
    inline std::string SpriteForBuilding(const Building& b) {
        return SpriteForBuilding(b.type, b.level);
    }

    inline std::vector<MenuEntry> MakeMenuForTile(const GameState& gs, int idx) {
        std::vector<MenuEntry> m;
        const Tile& t = gs.grid[idx];
        auto push = [&](MenuAction a, const wchar_t* txt, const char* icon = "") {
            MenuEntry e; e.action = a; e.text = txt; e.icon = icon; m.push_back(std::move(e));
            };

        if (t.b.level == 0 || t.b.type == BuildingType::None) {
            push(MenuAction::Build_Gold, L"���죺�����1", "gold1.tga");
            push(MenuAction::Build_Recruit, L"���죺��ļ��1", "human1.jpg");
            push(MenuAction::Build_Mage, L"���죺ħ��ʦ��1", "magic1.tga");
            push(MenuAction::Build_Shield, L"���죺�ܱ���1", "sheld1.tga");
            push(MenuAction::Build_Saint, L"���죺ʥŮ��1", "me1.tga");
            push(MenuAction::Cancel, L"ȡ��", "");
        }
        else {
            if (t.b.type == BuildingType::MageHouse || t.b.type == BuildingType::ShieldHouse)
                push(MenuAction::Train, L"ѵ��������1��λ��");

            const int maxLv = MaxLevelForBuilding(t.b.type);
            if (t.b.level < maxLv) {
                int coin = UpgradeCoinCost(t.b.level);
                int unit = UpgradeUnitCost(t.b.level);
                std::wstring s = L"������" + std::to_wstring(t.b.level + 1) + L"��������";
                if (coin > 0) s += std::to_wstring(coin) + L"���";
                if (unit > 0) {
                    if (coin > 0) s += L" + ";
                    s += std::to_wstring(unit) + L"��λ";
                }
                s += L"��";
                push(MenuAction::Upgrade, s.c_str());
            }

            {
                int r = RefundOnDemolish(t.b.level);
                std::wstring s = L"���������" + std::to_wstring(r) + L"���" + (t.b.level <= 1 ? L" + 1��λ" : L"") + L"��";
                push(MenuAction::Demolish, s.c_str());
            }
            push(MenuAction::Cancel, L"ȡ��");
        }
        return m;
    }


    inline void PlaceBuilding(Resources& r, Tile& t, BuildingType ty) {
        if (t.b.level != 0 || t.b.type != BuildingType::None) return;
        if (r.units < 1) return;
        r.units -= 1; t.b.type = ty; t.b.level = 1;
    }

    inline void UpgradeBuilding(Resources& r, Tile& t) {
        if (t.b.level <= 0) return;
        const int maxLv = MaxLevelForBuilding(t.b.type);
        if (t.b.level >= maxLv) return; // �� �����޾Ͳ���������

        int cc = UpgradeCoinCost(t.b.level);
        int uc = UpgradeUnitCost(t.b.level);
        if (r.coins < cc) return;
        if (r.units < uc) return;

        r.coins -= cc;
        r.units -= uc;
        t.b.level += 1;
    }


    inline void DemolishBuilding(Resources& r, Tile& t) {
        if (t.b.level <= 0) return;
        r.coins += RefundOnDemolish(t.b.level); t.b = Building{};
    }

    inline void TrainUnit(Resources& r, Tile& t) {
        if (t.b.level <= 0) return;
        if (t.b.type != BuildingType::MageHouse && t.b.type != BuildingType::ShieldHouse) return;
        if (r.units < 1) return;
        r.units -= 1;
        if (t.b.type == BuildingType::MageHouse) r.mageUnits += 1;
        else r.shieldUnits += 1;
    }

    inline void StartWave(GameState& gs) {
        for (const auto& tile : gs.grid) {
            const auto& b = tile.b;
            if (b.level <= 0) continue;
            if (b.type == BuildingType::Gold)         gs.res.coins += GoldIncome(b.level);
            else if (b.type == BuildingType::Recruit) gs.res.units += RecruitUnits(b.level);
        }
    }

    // ====== ֻ�����������ĺ�����ʵ�ַ� .cpp��======
    void InitGame(GameState& gs);
    void OpenMenu(GameState& gs, int tileIndex);
    void CloseMenu(GameState& gs);
    void OpenBattleConfirm(GameState& gs);
    void HandleInput(GameState& gs, const InputState& in);
    std::string HUDText(const GameState& gs);

} // namespace RTS9
