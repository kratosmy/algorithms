#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> path;
vector<bool> check(15, false); 

void dfs(int u) {
	if (u == n + 1) {
		for (int i = 0; i < n; i ++) {
			cout << path[i] << ' ';
		}
		puts("");
		return;
	} 
	
	for (int i = 1; i <= n; i ++) {
	    if (!check[i]) {
            path.push_back(i);
            check[i] = true;
            dfs(u + 1);
            check[i] = false;
	    	path.pop_back();
	    }
	}
}

int main() {
	scanf("%d", &n);

	dfs(1);

	return 0;
}