#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int n, m;
int maze[N][N], path[N][N];

typedef pair<int, int> PII;

int bfs() {
    int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

    memset(path, -1, sizeof path);
    path[0][0] = 0;

    queue<PII> q;
    q.push({0, 0});
    
    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++) {
            int new_x = t.first + dx[i], new_y = t.second + dy[i];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && maze[new_x][new_y] == 0 && path[new_x][new_y] == -1) {
                q.push({new_x, new_y});
                path[new_x][new_y] = path[t.first][t.second] + 1;
            } 
        }
    }

    return path[n - 1][m - 1];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int num;
            cin >> num;
            maze[i][j] = num;
        }
    }

    cout << bfs() << endl;;
    
    return 0;
}