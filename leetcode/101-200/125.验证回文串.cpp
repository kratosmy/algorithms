#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool check(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }

    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < n && j >= 0; i ++, j --) {
            while (i < j && !check(s[i])) i ++;
            while (i < j && !check(s[j])) j --;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};