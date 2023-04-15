#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
    核心在于unordered_map的count的函数的使用，因为unordered_map不允许重复的key，
    所以如果count返回1，说明已经存在了，如果返回0，说明不存在，可以插入。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> heap;
        for (int i = 0; i <= nums.size(); i++) {
            int r = target - nums[i];
            if (heap.count(r)) return {heap[r], i};
            heap[nums[i]] = i;
        }
        return {};
    }
};