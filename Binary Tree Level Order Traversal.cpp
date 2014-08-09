/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7


return its level order traversal as:

[
[3],
[9,20],
[15,7]
]
*/

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int>> ans;
		if (root == NULL) return ans;

		queue<TreeNode *> one, another;
		one.push(root);

		while (!one.empty() || !another.empty()) {
			if (!one.empty()) {
				vector<int> cur_ans;
				while (!one.empty()) {
					TreeNode * node = one.front();
					cur_ans.push_back(node->val);
					if (node->left != NULL) another.push(node->left);
					if (node->right != NULL) another.push(node->right);
					one.pop();
				}
				ans.push_back(cur_ans);
			}
			if (!another.empty()) {
				vector<int> cur_ans;
				while (!another.empty()) {
					TreeNode *node = another.front();
					cur_ans.push_back(node->val);
					if (node->left != NULL) one.push(node->left);
					if (node->right != NULL) one.push(node->right);
					another.pop();
				}
				ans.push_back(cur_ans);
			}
		}
		return ans;
	}
};