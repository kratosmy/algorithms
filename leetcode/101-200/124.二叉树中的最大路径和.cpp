#include <bits/stdc++.h>

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
	int ans = INT_MIN;

    int maxPathSum(TreeNode* root) {
    	dfs(root);
    	return ans;
    }

    int dfs(TreeNode* root) {
    	if (!root) return 0;
    	int left = max(0, dfs(root->left)), right = max(0, dfs(root->right));
    	ans = max(ans, left + right + root->val);
    	return root->val + max(left, right); 
    }
}; 