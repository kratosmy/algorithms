#include <iostream>

using namespace std;

int lowbit(int n) {
    return n & -n;
}

int main() {
    int t, x;
    cin >> t;
    while (t --) {
        int res = 0;
        cin >> x;
        while (x) x -= lowbit(x), res ++;
        cout << res << ' ';
    }
    return 0;
}