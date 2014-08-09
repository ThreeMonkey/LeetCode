/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/
* /
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
* Definition for binary tree
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		if (root == NULL) {
			return v_inorder;
		}

		if (root->left) {
			inorderTraversal(root->left);
		}
		v_inorder.push_back(root->val);
		if (root->right) {
			inorderTraversal(root->right);
		}

		return v_inorder;
	}
	vector<int> v_inorder;
};