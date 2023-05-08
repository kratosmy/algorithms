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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> res;
    	queue<TreeNode*> q;
    	if (root) q.push(root);
    	while (q.size()) {
    		vector<int> level;
    		int len = q.size();
    		while (len --) {
    			auto node = q.front();
    			level.push_back(node->val);
    			q.pop();
    			if (node->left) q.push(node->left);
    			if (node->right) q.push(node->right);
    		}
    		res.push_back(level);
    	}
    	reverse(res.begin(), res.end());
    	return res;
    }
};