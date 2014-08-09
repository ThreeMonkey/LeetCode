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

����˼·��
�ݹ飺��ָ�����ָ�룬�ԳƵݹ飬��������󡱺͡��ҵ��ҡ���Ӧ��������ҡ��͡��ҵ��󡱶�Ӧ��

�ǵݹ飺����������������������������������������������������������˳��Ƚ�ÿ��Ԫ���Ƿ���ȡ�
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