#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 100010;
int h[N], siz;

void down(int u) {
	int t = u;
	if (u * 2 <= siz && h[u * 2] < h[t]) t = u * 2;
	if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;

	if (u != t) {
		swap(h[u], h[t]);
		down(t);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
	siz = n;

	for (int i = n / 2; i > 0; i --) down(i);
	while (m --) {
		printf("%d ", h[1]);
		h[1] = h[siz];
		siz --;
		down(1);
	}	
}