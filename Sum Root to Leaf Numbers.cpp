/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

1
/ \
2   3


The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

解题思路：
利用深搜找到所有路径上表示的数，然后把它们加起来。
*/
#include <iostream>
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
	void dfs(TreeNode *root, int cur_ans, int &ans) {
		if (root == NULL) return;

		if (root->left == NULL && root->right == NULL) ans += (cur_ans * 10 + root->val);
		if (root->left != NULL) dfs(root->left, cur_ans * 10 + root->val, ans);
		if (root->right != NULL) dfs(root->right, cur_ans * 10 + root->val, ans);
		return;
	}
	int sumNumbers(TreeNode *root) {
		int ans = 0;
		dfs(root, 0, ans);

		return ans;
	}
};