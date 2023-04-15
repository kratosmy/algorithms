#include <iostream>
#include <unordered_map>

using namespace std;

/* 
    利用双指针，用hashmap存储当前字符出现的次数，如果有重复，则左指针右移，直到没有重复。
    然后利用右指针遍历整个字符串，找出最长无重复子串。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> heap;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            heap[s[i]]++;
            while (heap[s[i]] > 1) heap[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
    }
};  