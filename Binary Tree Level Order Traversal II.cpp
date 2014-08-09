/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7


return its bottom-up level order traversal as:

[
[15,7]
[9,20],
[3],
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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > ans;
		if (root == NULL) return ans;
		queue<TreeNode*> one;
		queue<TreeNode*> another;
		vector<int> cur_ans;
		TreeNode* cur_node;

		one.push(root);

		while (!one.empty() || !another.empty()) {
			if (!one.empty()) {
				while (!one.empty()) {
					cur_node = one.front();
					one.pop();
					cur_ans.push_back(cur_node->val);
					if (cur_node->left) another.push(cur_node->left);
					if (cur_node->right) another.push(cur_node->right);
				}
				ans.push_back(cur_ans);
				cur_ans.clear();
			}
			if (!another.empty()) {
				while (!another.empty()) {
					cur_node = another.front();
					another.pop();
					cur_ans.push_back(cur_node->val);
					if (cur_node->left) one.push(cur_node->left);
					if (cur_node->right) one.push(cur_node->right);
				}
				ans.push_back(cur_ans);
				cur_ans.clear();
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};