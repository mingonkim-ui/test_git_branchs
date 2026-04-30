#pragma once
#include <windows.h>

class ScreenSaverApp {
public:
    ScreenSaverApp(HWND hwnd);
    ~ScreenSaverApp();
    
    // 매 프레임마다 호출되어 화면을 업데이트하고 그리는 함수
    void UpdateAndDraw();

private:
    HWND m_hwnd;
    HDC m_hdc;
    int m_width;
    int m_height;
    
    // 애니메이션을 위한 변수 (예: 튕기는 공의 위치와 속도)
    int m_x, m_y;
    int m_dx, m_dy;
};