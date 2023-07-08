#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    unordered_set<string> hash;
    vector<string> ans;
    vector<bool> f;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for (auto& word : wordDict) hash.insert(word);
        f.resize(n + 1);
        f[n] = true;

        for (int i = n - 1; i >= 0; i --) {
            for (int j = i; j < n; j ++) {
                if (hash.count(s.substr(i, j - i + 1)) && f[j + 1]) f[i] = true;
            }
        }
        dfs(s, 0, "");

        return ans;
    }

    void dfs(string& s, int u, string path) {
        if (u == n) {
            path.pop_back();
            ans.push_back(path);
        } else {
            for (int i = u; i < n; i ++) {
                if (hash.count(s.substr(u, i - u + 1)) && f[i + 1]) {
                    dfs(s, i + 1, path + s.substr(u, i - u + 1) + ' ');
                }
            }
        }
    }
};