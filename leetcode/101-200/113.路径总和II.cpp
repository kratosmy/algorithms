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
	vector<vector<int>> ans;
	vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    	dfs(root, targetSum, path);
    	return ans;
    }

    void dfs(TreeNode* root, int targetSum, vector<int> path) {
        if (!root) return;
    	if (!root->left && !root->right) {
            path.push_back(root->val);
    		if (accumulate(path.begin(), path.end(), 0) == targetSum) ans.push_back(path);
    		return;
    	}

    	path.push_back(root->val);
    	dfs(root->left, targetSum, path);
    	dfs(root->right, targetSum, path);
    	path.pop_back();
    }
};