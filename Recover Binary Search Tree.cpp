/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

解题思路：
中序遍历BST，在遍历过程中记录出现错误的节点。err_1是第一次发生pre_val > root_val的节点，err_2是最后
一次发生pre_val > root_val的节点。最后交换err_1->val 和 err_2->val
*/

#include <iostream>
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
	TreeNode *err_1, *err_2;
	TreeNode *pre;

	void find2Nodes(TreeNode *root) {
		if (root == NULL) return;

		if (root->left != NULL) {
			find2Nodes(root->left);
		}
		if (pre != NULL && pre->val >= root->val) {
			if (err_1 == NULL) err_1 = pre; //第一个出错的节点， 在最前
			err_2 = root; //第二个出错的节点，在最后
		}
		pre = root;
		if (root->right != NULL) {
			find2Nodes(root->right);
		}
	}

	void recoverTree(TreeNode *root) {
		if (root == NULL) return;

		err_1 = err_2 = pre = NULL;

		find2Nodes(root);
		swap(err_1->val, err_2->val);
	}
};