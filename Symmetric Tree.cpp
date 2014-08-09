/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3


But the following is not:

1
/ \
2   2
\   \
3    3


Note:
Bonus points if you could solve it both recursively and iteratively.

解题思路：
递归：左指针和右指针，对称递归，即“左的左”和“右的右”对应，“左的右”和“右的左”对应。

非递归：中序遍历左子树，将结果保存起来，中序遍历右子树将结果保存起来；顺序比较每个元素是否相等。
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
	bool judge(TreeNode *p_left, TreeNode *p_right) {
		if (p_left == NULL && p_right == NULL) {
			return true;
		}
		else if ((p_left != NULL && p_right == NULL) || (p_left == NULL && p_right != NULL)) {
			return false;
		}

		if (p_left->val != p_right->val) return false;

		/*/
		if ((p_left->left != p_right->right && (p_left->left == NULL || p_right->right == NULL)) ||
			(p_left->right != p_right->left && (p_left->right == NULL || p_right->left == NULL))) {
			return false;
		}
		//*/

		return judge(p_left->left, p_right->right) && judge(p_left->right, p_right->left);

	}
	bool isSymmetric(TreeNode *root) {
		if (root == NULL || (root->left == NULL && root->right == NULL)) {
			return true;
		}
		else if (root->left == NULL || root->right == NULL) {
			return false;
		}
		if (root->left->val == root->right->val) {
			return judge(root->left, root->right);
		}
		return false;
	}
};