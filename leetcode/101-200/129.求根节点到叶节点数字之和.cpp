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
	int res = 0;

    void dfs(TreeNode* node, int path) {
    	if (!node) return;

        if (node && !node->left && !node->right) {
    		res += (path * 10 + node->val);
    		return;
    	}

    	dfs(node->left, path * 10 + node->val);
    	dfs(node->right, path * 10 + node->val);
    }

    int sumNumbers(TreeNode* root) {
    	dfs(root, 0);
    	return res;
    }
};