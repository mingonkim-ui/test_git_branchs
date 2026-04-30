#include "ScreenSaver.h"

ScreenSaverApp::ScreenSaverApp(HWND hwnd) : m_hwnd(hwnd) {
    // 화면 크기 가져오기
    RECT rect;
    GetClientRect(hwnd, &rect);
    m_width = rect.right;
    m_height = rect.bottom;
    
    // 초기 위치 및 이동 속도 설정
    m_x = m_width / 2; 
    m_y = m_height / 2;
    m_dx = 5; 
    m_dy = 5;
    
    // Device Context 가져오기
    m_hdc = GetDC(hwnd);
}

ScreenSaverApp::~ScreenSaverApp() {
    // 자원 해제
    ReleaseDC(m_hwnd, m_hdc);
}

void ScreenSaverApp::UpdateAndDraw() {
    // 1. 배경을 검은색으로 지우기
    RECT rect = { 0, 0, m_width, m_height };
    FillRect(m_hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

    // 2. 위치 업데이트 및 화면 가장자리 충돌 처리
    m_x += m_dx; 
    m_y += m_dy;
    
    if (m_x <= 0 || m_x >= m_width) m_dx = -m_dx;
    if (m_y <= 0 || m_y >= m_height) m_dy = -m_dy;

    // 3. 도형(공) 그리기
    SelectObject(m_hdc, GetStockObject(WHITE_PEN));
    SelectObject(m_hdc, GetStockObject(WHITE_BRUSH));
    Ellipse(m_hdc, m_x - 30, m_y - 30, m_x + 30, m_y + 30);
}