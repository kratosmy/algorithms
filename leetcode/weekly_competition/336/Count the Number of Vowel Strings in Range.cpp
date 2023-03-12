#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<char> ref = {'a', 'e', 'i', 'o', 'u'};

    int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i ++) {
            if (judge(words[i])) res ++;
        }
        return res;
    }

    bool judge(string s) {
        if (find(ref.begin(), ref.end(), s[0]) != ref.end() && find(ref.begin(), ref.end(), s[s.size() - 1]) != ref.end()) return true;
        return false;
    }
};