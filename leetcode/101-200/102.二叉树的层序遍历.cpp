#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    queue<TreeNode*> path;
    vector<vector<int>> ans;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return ans;

        path.push(root);
        auto temp = path;
        while(path.size()) {
            vector<int> sub_path;
            for (int i = 0; i < temp.size(); i ++) {
                auto node = path.front();
                path.pop();
                sub_path.push_back(node->val);
                if (node->left) path.push(node->left);
                if (node->right) path.push(node->right);
            }
            temp = path;
            ans.push_back(sub_path);
        }
        return ans;
    }
};