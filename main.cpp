#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>

#include "win32_platform.cpp"
#include "window.h"

using namespace std;

int main(){
    cout << "salut la team\n" << endl;

    Window* pWindow = new Window();

    bool running = true;
    while (running){

        if (!pWindow->processmessages())
        {
            cout << "fermeture\n" << endl;
            running = false;
        }

        // render
        Sleep(10);
    }

    delete pWindow;

    return 0;
}