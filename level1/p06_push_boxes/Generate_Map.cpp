//
// Created by Brian on 2026/9/23.
//
#include<bits/stdc++.h>
using namespace std;
string makeMapFilename(int level) {
    ostringstream oss;
    oss<<"Map"<<setw(2)<<setfill('0')<<level<<".txt";
    return oss.str();
}S
int n = 10, m = 3, st = 50;
int tx[4] = {0, 0, -1, 1}, ty[4] = {-1, 1, 0, 0};
char str[10][10];
int nowplace[3];
void generate_map() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            str[i][j] = ' ';
    mt19937 rnd();
    for (int i = 0; i < 3; i++) {
        nowplace[i] = rnd() % 100;
    }
}
void print_map(int level) {
    ofstream out(makeMapFilename(level));
}