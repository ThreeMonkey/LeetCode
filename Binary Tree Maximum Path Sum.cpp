/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

1
/ \
2   3


Return 6.

解题思路：
采用后序遍历。设当前根节点的左子树的最大和为left_ans，右子树的最大和为right_ans;则ans 是 root->val + left_ans 、 root->val + right_ans 和 root->val + left_ans + right_ans的最大值。

而以该根节点的子树对父节点的贡献为 root->val + max(left_ans, right_ans);
*/
#include <algorithm>
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
	int post_order(TreeNode *root, int &ans) {
		if (root == NULL) return 0;

		int left_ans = 0, right_ans = 0;
		if (root->left) left_ans = max(left_ans, post_order(root->left, ans));

		if (root->right) right_ans = max(right_ans, post_order(root->right, ans));

		ans = max(ans, root->val + left_ans + right_ans);
		return max(root->val + left_ans, root->val + right_ans);
	}
	int maxPathSum(TreeNode *root) {
		if (root == NULL) return 0;

		int ans = root->val;
		post_order(root, ans);

		return ans;
	}
};