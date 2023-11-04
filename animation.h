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

void loadingBar()
{
    //loading border up-down
    for (int x = 25; x < 65; x++)
    {
        gotoxy(x, 17);
        printf("%c", 205);
        gotoxy(x, 19);
        printf("%c", 205);
    }
    //loading border left-right
    gotoxy(25, 18);
    printf("%c", 186);
    gotoxy(65, 18);
    printf("%c", 186);

    // top left corner
    gotoxy(25, 17);
    printf("%c", 201);
    // top right corner
    gotoxy(65, 17);
    printf("%c", 187);
    // bottom left corner
    gotoxy(25, 19);
    printf("%c", 200);
    // bottom right corner
    gotoxy(65, 19);
    printf("%c", 188);

    for (int percent = 0; percent <= 100; percent++)
    {
        int loadStart = 25 + 1;                     //start filling form here
        int length = (65 - 25) - 1;                 //length of empty area in the loading border

        int barLength = ((length) * percent) / 100; // Calculate the number of characters to fill based on the percentage
        for (int i = 0; i < barLength; i++)
        {
            gotoxy(loadStart + i, 18);
            printf("%c", 178);
        }
        gotoxy(35, 20);
        cout << "Loading . . . " << percent << " %";
        Sleep(35);
        // Clear any remaining characters in the loading bar
        for (int i = barLength; i < length; i++)
        {
            gotoxy(loadStart + i, 18);
            printf(" ");
        }
    }
}

#endif