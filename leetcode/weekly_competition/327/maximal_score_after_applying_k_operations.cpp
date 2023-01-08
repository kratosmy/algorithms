#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (auto& num : nums) {
            heap.push(num);
        }
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            int max = heap.top();
            sum += max;
            heap.pop();
            heap.push((max + 2) / 3); // don't use ceil() here;
        }
        return sum;
    }
};