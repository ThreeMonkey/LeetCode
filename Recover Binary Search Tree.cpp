/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

����˼·��
�������BST���ڱ��������м�¼���ִ���Ľڵ㡣err_1�ǵ�һ�η���pre_val > root_val�Ľڵ㣬err_2�����
һ�η���pre_val > root_val�Ľڵ㡣��󽻻�err_1->val �� err_2->val
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
			if (err_1 == NULL) err_1 = pre; //��һ������Ľڵ㣬 ����ǰ
			err_2 = root; //�ڶ�������Ľڵ㣬�����
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