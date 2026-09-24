#include <iostream>
#include <chrono>
using namespace std;
char tx[5] = {' ', 'A', 'B', ' ', 'C'};
void work(int u, int v) {
    cout<< tx[u] << " -> " << tx[v] << '\n';
}
void sol(int h, int now, int to) {
    if (h == 1)
        return work(now, to), void();
    sol(h - 1, now, 7 ^ now ^ to);
    work(now, to);
    sol(h - 1, 7 ^ now ^ to, to);
}
int main() {
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    auto t0 = chrono::steady_clock::now();
    sol(5, 1, 4);
    auto t1 = chrono::steady_clock::now();
    double ms = chrono::duration<double, std::milli>(t1 - t0).count();
    cout << "Total time: " << ms << "ms\n";
    return 0;
}