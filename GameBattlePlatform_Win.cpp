#include "GameBattlePlatform.h"

// 只有 Windows 平台才启用本实现；其他平台编译成空单元
#if defined(_WIN32)

#include "direct3d.h"  // 注意：只有平台层依赖 DX，GameBattle 不再包含 DX/WinAPI

bool Battle_GetBackbufferSize(int& outW, int& outH)
{
    outW = (int)Direct3D_GetBackBufferWidth();
    outH = (int)Direct3D_GetBackBufferHeight();
    return (outW > 0 && outH > 0);
}

#endif // _WIN32
