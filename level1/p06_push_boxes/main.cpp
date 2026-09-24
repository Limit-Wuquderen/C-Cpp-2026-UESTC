#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
const int WIDTH = 41, HEIGHT = 41;
char maze[WIDTH][HEIGHT];
int player_X, player_Y, exit_X, exit_Y, steps;
mt19937 mt(time(nullptr));
void digdig(int x, int y) {
    maze[x][y] = ' ';
    int tx[4] = {0, 0, -2, 2}, ty[4] = {-2, 2, 0, 0};
    for (int i = 1; i <= 10; i++) {
        int o = mt() % 4, s = mt() % 4;
        swap(tx[o], tx[s]);
        swap(ty[o], ty[s]);
    }
    for (int i = 0; i <= 3; i++) {
        int nx = x + tx[i], ny = y + ty[i];
        if (nx > 0 && nx < WIDTH && ny > 0 && ny < HEIGHT && maze[nx][ny] == '#') {
            maze[(x + nx) >> 1][(y + ny) >> 1] = ' ';
            digdig(nx, ny);
        }
    }
}
void Generate_Maze() {
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            maze[i][j] = '#';
    digdig(1, 1);
}
void Print_Maze() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (i == player_X && j == player_Y)
                cout << 'P';
            else if (i == exit_X && j == exit_Y)
                cout << 'E';
            else cout << maze[i][j];
        }
        cout << endl;
    }
}
void draw() {
    system("cls");
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if (x == player_X && y == player_Y)
                cout << 'P';  // 玩家
            else if (x == exit_X && y == exit_Y)
                cout << 'E';  // 出口
            else
                cout << maze[x][y];
        }
        cout << '\n';
    }
    cout << "\n用方向键移动，按 Q 退出。  已走步数：" << steps << "\n";
}
const int KEY_OTHER = 0;
const int KEY_UP    = 1;
const int KEY_DOWN  = 2;
const int KEY_LEFT  = 3;
const int KEY_RIGHT = 4;
const int KEY_QUIT  = 5;
int tx[5] = {0, -1, 1, 0, 0}, ty[5] = {0, 0, 0, -1, 1};
int readKey() {
    int c = _getch();
    if (c == 0 || c == 224) {           // 方向键的前导字节
        int c2 = _getch();
        if (c2 == 72) return KEY_UP;
        if (c2 == 80) return KEY_DOWN;
        if (c2 == 75) return KEY_LEFT;
        if (c2 == 77) return KEY_RIGHT;
        return KEY_OTHER;
    }
    if (c == 'q' || c == 'Q') return KEY_QUIT;
    return KEY_OTHER;
}
int main() {
    SetConsoleOutputCP(CP_UTF8); //UTF-8
    Generate_Maze();
    player_X = 1, player_Y = 1, exit_X = WIDTH - 2, exit_Y = HEIGHT - 2, steps = 0;
    while (true) {
        draw();
        if (player_X == exit_X && player_Y == exit_Y) {
            cout << "\n恭喜，你赢得了游戏！\n";
            break;
        }
        int key = readKey();
        if (key == KEY_QUIT) {
            cout << "\n已退出游戏。\n";
            system("pause");
            return 0;
        }
        int nx = player_X + tx[key], ny = player_Y + ty[key];
        if (nx > 0 && nx < WIDTH && ny > 0 && ny < HEIGHT && maze[nx][ny] == ' ') {
            player_X = nx, player_Y = ny, steps++;
        }
    }
    system("pause");
    return 0;
}