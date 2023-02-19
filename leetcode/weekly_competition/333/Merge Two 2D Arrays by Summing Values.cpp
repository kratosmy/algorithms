#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> res;

        unordered_map<int, int> hash;
        for (auto item : a) {
            hash[item[0]] = item[1]; 
        }

        for (auto item : b) {
            if (hash.count(item[0])) hash[item[0]] += item[1];
            else hash[item[0]] = item[1]; 
        }

        for (auto h : hash) {
            res.push_back({h.first, h.second});
        }

        sort(res.begin(), res.end());
         
        return res;
    }
};