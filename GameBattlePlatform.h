#pragma once

// 平台适配层：统一查询当前渲染目标分辨率（像素）
// 返回 true 表示拿到有效尺寸
bool Battle_GetBackbufferSize(int& outW, int& outH);

// -------- 平台宏约定 --------
// Windows:   _WIN32 由编译器自动定义
// Switch端:  自行在工程“预处理器定义”里添加 BUILD_FOR_SWITCH
//           （避免误开两个平台：若 _WIN32 与 BUILD_FOR_SWITCH 同时存在会触发编译错误）
#if defined(_WIN32) && defined(BUILD_FOR_SWITCH)
#error "Both _WIN32 and BUILD_FOR_SWITCH defined. Define only one platform."
#endif
