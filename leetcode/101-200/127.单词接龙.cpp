#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    	unordered_set<string> S;
    	unordered_map<string, int> dist;
    	queue<string> q;

    	for (string& word : wordList) S.insert(word);
    	q.push(beginWord);
        dist[beginWord] = 0;

    	while (q.size()) {
    		string t = q.front();
    		q.pop();
    		string r = t;
    		for (int i = 0; i < t.size(); i ++) {
    			t = r;
    			for (char j = 'a'; j <= 'z'; j ++) {
    				if (t[i] != j) {
    					t[i] = j;
    					if (S.count(t) && !dist.count(t)) {
    						dist[t] = dist[r] + 1;
    						if (t == endWord) return dist[t] + 1;
    						q.push(t);
    					}
    				}
    			}
    		}
    	}
    	return 0;
    }
};