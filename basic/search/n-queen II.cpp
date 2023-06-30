#include <iostream>

using namespace std;

const int N = 10;
int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s) {
    if (y == n) {
        y = 0;
        x += 1;
    }

    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; i ++) puts(g[i]);
            puts("");
        }
        return;
    } 
    // not put chess
    dfs(x, y + 1, s);
    // put chess
    if (!row[x] && !col[y] && !dg[x + y] && !udg[y - x + n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[y - x + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[y - x + n] = false;
        g[x][y] = '.';
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            g[i][j] = '.';
        }
    }

    dfs(0, 0, 0);
}