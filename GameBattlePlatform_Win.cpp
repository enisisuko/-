#include "GameBattlePlatform.h"

// ֻ�� Windows ƽ̨�����ñ�ʵ�֣�����ƽ̨����ɿյ�Ԫ
#if defined(_WIN32)

#include "direct3d.h"  // ע�⣺ֻ��ƽ̨������ DX��GameBattle ���ٰ��� DX/WinAPI

bool Battle_GetBackbufferSize(int& outW, int& outH)
{
    outW = (int)Direct3D_GetBackBufferWidth();
    outH = (int)Direct3D_GetBackBufferHeight();
    return (outW > 0 && outH > 0);
}

#endif // _WIN32
