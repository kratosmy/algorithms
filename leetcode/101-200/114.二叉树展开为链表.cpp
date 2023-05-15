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
    void flatten(TreeNode* root) {
    	while (root) {
    		auto p = root->left;
    		if (p) {
    			while (p->right) p = p->right;
    			p->right = root->right;
    			root->right = root->left;
    			root->left = NULL;
    		}
    		root = root->right;
    	}
    }
};