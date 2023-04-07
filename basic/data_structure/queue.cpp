#include <iostream>

using namespace std;

const int N = 100010;

int stk[N];

int main() {
    int m, x;
    cin >> m;

    int tt = 0, hh = 0;
    while (m --) {
        string op;
        cin >> op;
        if (op == "push") {
            cin >> x;
            stk[tt ++] = x; 
        } else if (op == "pop") {
            hh ++;
        } else if (op == "empty") {
            if (hh >= tt) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << stk[hh] << endl;
        }
    }
}