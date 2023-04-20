#include <iostream>

using namespace std;

const int N = 100010;

int s[N][26], cnt[N], idx;
char str[N];

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if (!s[p][u]) s[p][u] = ++ idx;
        p = s[p][u];
    }
    cnt[p] ++;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if (!s[p][u]) return 0;
        p = s[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    cin >> n;
    while (n --) {
        char op[2];
        cin >> op >> str;
        if (op[0] == 'I') {
            insert(str);
        } else {
            cout << query(str) << endl;
        }
    }
    return 0;
}