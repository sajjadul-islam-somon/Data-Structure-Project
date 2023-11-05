#include <bits/stdc++.h>
#include <windows.h>

#ifndef animation
#define animation

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


#endif
