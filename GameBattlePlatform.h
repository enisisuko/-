#pragma once

// ƽ̨����㣺ͳһ��ѯ��ǰ��ȾĿ��ֱ��ʣ����أ�
// ���� true ��ʾ�õ���Ч�ߴ�
bool Battle_GetBackbufferSize(int& outW, int& outH);

// -------- ƽ̨��Լ�� --------
// Windows:   _WIN32 �ɱ������Զ�����
// Switch��:  �����ڹ��̡�Ԥ���������塱����� BUILD_FOR_SWITCH
//           ������������ƽ̨���� _WIN32 �� BUILD_FOR_SWITCH ͬʱ���ڻᴥ���������
#if defined(_WIN32) && defined(BUILD_FOR_SWITCH)
#error "Both _WIN32 and BUILD_FOR_SWITCH defined. Define only one platform."
#endif
