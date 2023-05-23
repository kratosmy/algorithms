#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 100010;
int h[N], ph[N], hp[N], siz;

void heap_swap(int a, int b) {
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u) {
	int t = u;
	if (u * 2 <= siz && h[u * 2] < h[t]) t = u * 2;
	if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;

	if (u != t) {
		heap_swap(u, t);
		down(t);
	}
}

void up(int u) {
	while (u / 2 && h[u / 2] > h[u]) {
		heap_swap(u / 2, u);
		u /= 2;
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