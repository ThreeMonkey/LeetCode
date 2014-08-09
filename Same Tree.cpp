/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

解题思路：
递归求解。先判断根，然后递归判断左子树和右子树
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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL){
			return true;
		}
		else if (p != NULL && q != NULL && p->val == q->val){
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else {
			return false;
		}
	}
};