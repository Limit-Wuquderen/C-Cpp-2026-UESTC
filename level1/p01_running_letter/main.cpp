#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    const string text = "HELLO";
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(screen, &cursor); //读出光标的设置
    cursor.bVisible = true;
    SetConsoleCursorInfo(screen, &cursor); //将隐藏的设置写回光标
    int x = 0, dir = 1;
    while (true) {
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(screen, &info); //读出当前窗口长
        int width = info.srWindow.Right - info.srWindow.Left + 1;
        int delayMs = 40;
        system("cls");
        cout<<"\r";
        for (int i = 1; i <= x; i++)
            cout<<" ";
        cout<<text;
        cout.flush(); //立即显示
        Sleep(delayMs); //停顿
        x += dir;
        if (x <= 0)
            dir = 1;
        if (x + text.size() >= width)
            dir = -1;
    }
    return 0;
}