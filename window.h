#pragma once

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


class Window{
    private:

    HINSTANCE m_hInstance;
    HWND m_hWnd;

    public:
    Window();
    Window(const Window&) = delete; // permet de supprimer les constructeurs par copie
    Window& operator =(const Window&) = delete;
    ~Window();

    bool processmessages();

};