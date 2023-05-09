#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m;
int p[N];
int siz[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void run() {
    cin >> n >> m;
    for (int i = 0; i <= n; i ++) {
        p[i] = i;
        siz[i] = 1;
    }

    while (m --) {
        char op[5];
        int a, b;
        scanf("%s", &op);

        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) continue;
            siz[find(b)] += siz[find(a)];
            p[find(a)] = find(b);
        } else if (op[1] == '1') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        } else {
            scanf("%d", &a);
            printf("%d\n", siz[find(a)]);
        }
    }
}   

int main() {
    #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("inputf.in", "r", stdin);
        freopen("outputf.out", "w", stdout);
    #endif
   
    run();

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif

   return 0;
}