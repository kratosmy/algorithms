#include <vector>

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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (root->left) dfs(root->left);
        if (root) ans.push_back(root->val);
        if (root->right) dfs(root->right);
    }
};