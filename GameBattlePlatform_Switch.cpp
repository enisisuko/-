#include "GameBattlePlatform.h"

// ֻ�� Switch ����ʱ�����ñ�ʵ�֣�Windows �±���ɿյ�Ԫ�����ظ�����
#if defined(BUILD_FOR_SWITCH)

// ���������ʵ NVN/GL �Ľӿڣ��������������������ã�
// extern "C" bool Switch_GetFramebufferSize(int* w, int* h);

bool Battle_GetBackbufferSize(int& outW, int& outH)
{
    // TODO: �������ʵ֡����ߴ�ӿ��滻
    outW = 1280;
    outH = 720;
    return true;
}

#endif // BUILD_FOR_SWITCH
