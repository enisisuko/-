#include "GameBattlePlatform.h"

// 只有 Switch 构建时才启用本实现；Windows 下编译成空单元避免重复定义
#if defined(BUILD_FOR_SWITCH)

// 如果你有真实 NVN/GL 的接口，可以在这里声明并调用：
// extern "C" bool Switch_GetFramebufferSize(int* w, int* h);

bool Battle_GetBackbufferSize(int& outW, int& outH)
{
    // TODO: 用你的真实帧缓冲尺寸接口替换
    outW = 1280;
    outH = 720;
    return true;
}

#endif // BUILD_FOR_SWITCH
