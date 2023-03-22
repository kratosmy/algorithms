#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;

        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (matrix[mid / n][mid % n] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[r / n][r % n] == target;
    }
};

