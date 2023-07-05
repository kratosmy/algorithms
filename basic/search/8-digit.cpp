#include <bits/stdc++.h>

using namespace std;

int bfs(string start) {
    queue<string> q;
    unordered_map<string, int> d;
    d[start] = 0;
    q.push(start);
    // use string to present a matrix(state)
    string end = "12345678x";

    while (!q.empty()) {
        string t = q.front();
        q.pop();

        int distance = d[t];
        // final state
        if (t == end) return distance;

        int pos = t.find('x');
        // transfer 1-d index to a 2-d index
        int x = pos / 3, y = pos % 3;
        int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                int cur_pos = a * 3 + b;
                swap(t[pos], t[cur_pos]);
                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[pos], t[cur_pos]);
            }
        }
    }

    return -1;
}

int main() {
    char input[9];
    int n = 0;
    while (n < 9) {
        char c;
        cin >> c;
        input[n ++] = c;
    }

    cout << bfs(input) << endl;

    return 0;
}