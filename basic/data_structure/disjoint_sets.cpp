#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

// 只有当某个节点再次被Merge的时候，它才会意识到自己的父节点变了，于是加以更新，达到路径压缩的效果
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) p[i] = i;

    char op;
    int a, b;
    while (m --) {
        scanf("%s%d%d", &op, &a, &b);
        if (op == 'M') {
            p[find(a)] = find(b);
        } else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}