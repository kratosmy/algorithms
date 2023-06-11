#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int idx = 0;
        while (idx < n && s[idx] == 'a') idx ++;
        if (idx == n) {
        	s[n - 1] = 'z';
        } else {
        	for (int i = idx; i < n; i ++) {
        		if (s[i] != 'a') s[i] = s[i] - 1;
        		else break;
        	}
        }
	    return s;
    }
};