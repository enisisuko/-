#pragma once
// BuildUI.h
#pragma once
#include "BuildSystem.h"
void InitBuildUI();
void UninitBuildUI();

// �ڵ�ͼ�ϰѽ���ͼ�껭����
void DrawBuildWorld(const RTS9::GameState& gs);

// �����β˵���Χ�����λ�ã�
void DrawBuildMenu(const RTS9::GameState& gs);

void BuildUI_ResetMenuState();
void BuildUI_Tick();                               // ֻ���£�������
void BuildUI_DrawTopMost(const RTS9::GameState&);