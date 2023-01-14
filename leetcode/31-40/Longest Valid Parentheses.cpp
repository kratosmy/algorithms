#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        // according to the fact that we can split the string into several parts, 
        // and each legal part is a valid parentheses plus one closing bracket, we can prove this fact using proof by contradiction.
        for (int i = 0, start = -1; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            else {
                if (stk.size()) {
                    stk.pop();
                    if (stk.size()) {
                        res = max(res, i - stk.top());
                    } else {
                        res = max(res, i - start);
                    }
                } else {
                    start = i;   
                }
            }
        }
        return res;
    }
};