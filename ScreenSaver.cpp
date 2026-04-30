#include <windows.h>
#include <scrnsave.h>
#include "ScreenSaver.h"

// 화면보호기 앱 객체 포인터
ScreenSaverApp* g_pApp = nullptr;

// 1. 메인 화면보호기 프로시저 (필수 구현)
LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE:
            // 화면보호기 시작 시 객체 생성 및 타이머 설정 (약 30fps)
            g_pApp = new ScreenSaverApp(hWnd);
            SetTimer(hWnd, 1, 33, NULL); 
            return 0;

        case WM_TIMER:
            // 타이머 주기에 맞춰 화면 업데이트
            if (g_pApp) {
                g_pApp->UpdateAndDraw();
            }
            return 0;

        case WM_DESTROY:
            // 화면보호기 종료 시 자원 해제
            if (g_pApp) {
                delete g_pApp;
                g_pApp = nullptr;
            }
            KillTimer(hWnd, 1);
            return 0;
    }
    // 처리하지 않은 메시지는 기본 프로시저로 전달
    return DefScreenSaverProc(hWnd, message, wParam, lParam);
}

// 2. 환경 설정 다이얼로그 프로시저 (필수 구현 - 빈 상태로 둠)
BOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    return FALSE; // 설정 화면이 없으므로 FALSE 반환
}

// 3. 다이얼로그 클래스 등록 (필수 구현)
BOOL WINAPI RegisterDialogClasses(HANDLE hInst) {
    return TRUE;
}