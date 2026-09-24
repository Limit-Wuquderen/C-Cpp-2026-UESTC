#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    bool flag = false;
    for (int i = 2; (long long)i * i <= n; i++)
        if (n % i == 0) {
            flag = 1;
            break;
        }
    if (n < 2)
        cout<<"NO"<<endl;
    else if (flag == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    system("pause");
    return 0;
}
