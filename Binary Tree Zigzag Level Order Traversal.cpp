/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7


return its zigzag level order traversal as:

[
[3],
[20,9],
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> ans;
		if (root == NULL) return ans;

		vector<TreeNode *> one, another;
		one.push_back(root);

		while (!one.empty() || !another.empty()) {
			if (!one.empty()) {
				vector<int> cur_ans;
				TreeNode * node = NULL;
				for (int i = 0; i < one.size(); i++) {
					node = one[i];
					cur_ans.push_back(node->val);
					if (node->left) another.push_back(node->left);
					if (node->right) another.push_back(node->right);
				}
				ans.push_back(cur_ans);
				one.clear();
			}
			if (!another.empty()) {
				vector<int> cur_ans;
				TreeNode * node = NULL;
				for (int i = 0; i < another.size(); i++) {
					node = another[i];
					cur_ans.push_back(node->val);
					if (node->left) one.push_back(node->left);
					if (node->right) one.push_back(node->right);
				}
				reverse(cur_ans.begin(), cur_ans.end());
				ans.push_back(cur_ans);
				another.clear();
			}
		}
		return ans;
	}
};