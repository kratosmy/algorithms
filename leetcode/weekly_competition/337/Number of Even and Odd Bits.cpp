#include <vector>

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        int idx = 0;
        while (n) {
            if (n % 2 && (idx == 0 || idx % 2 == 0)) even ++;
            else if (n % 2 && idx % 2 == 1) odd ++;
            idx ++;
            n /= 2;
        }
        return {even, odd};
    }
};