/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

1
/ \
2   3


Return 6.

����˼·��
���ú���������赱ǰ���ڵ��������������Ϊleft_ans��������������Ϊright_ans;��ans �� root->val + left_ans �� root->val + right_ans �� root->val + left_ans + right_ans�����ֵ��

���Ըø��ڵ�������Ը��ڵ�Ĺ���Ϊ root->val + max(left_ans, right_ans);
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