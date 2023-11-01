#include <bits/stdc++.h>
#include <windows.h>

#ifndef animation
#define animation

using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);


void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Animation()
{
    for (int i = 45; i >= 1; i--)
    {
        Sleep(30);
        gotoxy(1, i);
        // clreol();
    }
    for (int i = 1; i <= 20; i++)
    {
        // clreol();
        Sleep(40);
        gotoxy(1, i);
    }
}

#endif