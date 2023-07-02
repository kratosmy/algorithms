#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> ref;

    vector<vector<int>> findPrimePairs(int n) {
        for (int i = 0; i <= n; i ++) {
            if (isPrime(i)) ref.push_back(i);
        }

        vector<vector<int>> ans;

        int left = 0, right = ref.size() - 1;
        while (left <= right) {
            if (ref[left] + ref[right] == n) ans.push_back({ref[left ++], ref[right --]});
            else if (ref[left] + ref[right] < n) left ++;
            else right --;
        }

        return ans;
    }

    bool isPrime(int n) {
        if (n < 2)
            return false;
        if (n < 4)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
};