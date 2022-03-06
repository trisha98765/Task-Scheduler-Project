#include <iostream>
#include "../header/ColorManager.h"

using namespace std;

void setColor(int fg, int bg) {
    #ifdef WINDOWS
    // TODO
    // system("color ??");
    #else
    cout << "\e[4" << bg << "m";
    cout << "\e[0;9" << fg << "m";
    #endif
}

void clear() {
    #ifdef WINDOWS
    system("cls");
    #else
    system("clear");
    #endif
}
