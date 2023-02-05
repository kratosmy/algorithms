#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        unordered_set<char> hash{'a', 'e', 'i', 'o', 'u'};
        vector<int> ref(n);
        
        for (int i = 0; i < n; i++) {
            if (hash.count(words[i][0]) && hash.count(words[i].back())) ref[i] = 1;
        }

        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + ref[i - 1];
        }

        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = sum[queries[i][1] + 1] - sum[queries[i][0]];
        }

        return res;
    }
};