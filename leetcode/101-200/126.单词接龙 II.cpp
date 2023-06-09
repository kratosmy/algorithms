#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<string>> ans;
	vector<string> path;
	unordered_set<string> S;
	unordered_map<string, int> dist;
	
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	for (auto& word : wordList) S.insert(word);
    	queue<string> q;
    	q.push(beginWord);
    	dist[beginWord] = 0;

    	while (q.size()) {
    		auto t = q.front();
    		q.pop();
    		string r = t;
    		for (int i = 0; i < t.size(); i ++) {
    			t = r;
    			for (char j = 'a'; j <= 'z'; j ++) {
    				if (j != t[i]) {
    					t[i] = j;
    					if (S.count(t) && dist.count(t) == 0) {
    						dist[t] = dist[r] + 1;
    						if (t == endWord) break;
    						q.push(t);
    					}
    				}
    			}
    		}
    	}

    	if (dist.count(endWord)) {
    		path.push_back(beginWord);
    		dfs(beginWord, endWord);
    	}

    	return ans;
    }

    void dfs(string st, string ed) {
    	if (st == ed) {
    		ans.push_back(path);
    		return;
    	}

    	string r = st;
    	for (int i = 0; i < st.size(); i ++) {
    		st = r;
    		for (char j = 'a'; j < 'z'; j ++) {
    			if (j != r[i]) {
    				st[i] = j;
    				if (S.count(st) && dist[r] + 1 == dist[st]) {
    					path.push_back(st);
    					dfs(st, ed);
    					path.pop_back();
    				}
    			}
    		}
    	}
    }
};