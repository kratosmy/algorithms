#include <iostream>     
#include <algorithm>    

using namespace std;

class Solution {
public:
    // you need to prove that it is a monotonically decreasing function.
    int work(int n) {
        int res = 0;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) n /= i, res += i;
            }
        }
        if (n > 1) res += n;
        return res;
    }

    int smallestValue(int n) {
        while (true) {
            int next = work(n);
            if (next == n) break;
            n = next;
        }
        return n;
    }
};