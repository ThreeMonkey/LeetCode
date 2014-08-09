/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
����˼·��
�������������������preָ�룬�ڱ��������м�¼�Ƿ���Υ��BST�Ľڵ�Ĵ��ڡ�
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

	TreeNode * pre = NULL;
	bool isValidBST(TreeNode *root) {
		if (root == NULL) return true;

		if (root->left != NULL && !isValidBST(root->left)) return false;
		if (pre != NULL && pre->val >= root->val) return false;
		pre = root;
		if (root->right != NULL && !isValidBST(root->right)) return false;
		return true;
	}
};