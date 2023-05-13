#include<bits/stdc++.h>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, targetSum, root->val);
    }   

    bool dfs(TreeNode* root, int targetSum, int sum) {
        if (!root) return sum == targetSum;
        if (!root->left && !root->right) {
            return sum == targetSum;
        }
        if (root->left && root->right) return dfs(root->left, targetSum, sum + root->left->val) || dfs(root->right, targetSum, sum + root->right->val);
        if (root->left) return dfs(root->left, targetSum, sum + root->left->val);
        return dfs(root->right, targetSum, sum + root->right->val); 
    }
};