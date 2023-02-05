#include <cmath>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int> heap;
        for (int i = 0; i < n; i++) {
            heap.push(gifts[i]);
        }
        
        while (k) {
            int top = heap.top();
            int sqrt_top = int(sqrt(top));
            heap.pop();
            heap.push(sqrt_top);            
            k -= 1;
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += heap.top();
            heap.pop();
        }
        return res;
    }
};