#include <iostream>
#include <cstdio>
#include <chrono>
using namespace std;
const int N = 1000;
bool vis[N + 5];
int pri[N + 5], tot = 0;
int main() {
    auto t0 = chrono::steady_clock::now();
    for (int i = 2; i <= N; i++) {
        if (!vis[i])
            pri[++tot] = i;
        for (int j = 1; j <= tot; j++) {
            if (i * pri[j] > N)
                break;
            vis[i * pri[j]] = true;
            if (i % pri[j] == 0)
                break;
        }
    }
    auto t1 = chrono::steady_clock::now();
    for (int i = 1; i <= tot; i++)
        cout << pri[i] << " ";
    cout << endl;
    double ms = chrono::duration<double, std::milli>(t1 - t0).count();
    cout << "Total execution time: " << ms << "ms\n";
    return 0;
}