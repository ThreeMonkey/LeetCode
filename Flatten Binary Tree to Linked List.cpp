/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2   5
/ \   \
3   4   6


The flattened tree should look like:

1
\
2
\
3
\
4
\
5
\
6
Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

解题思路：
依照前序遍历二叉树的方法进行处理。
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
	void pre_order(TreeNode * root) {
		if (root == NULL) return;

		if (root->left != NULL)    pre_order(root->left);
		if (root->right != NULL) pre_order(root->right);

		if (root->left != NULL) {
			TreeNode *cur = root->left;
			while (cur->right != NULL) {
				cur = cur->right;
			}
			cur->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		return;
	}
	void flatten(TreeNode *root) {
		pre_order(root);
	}
};