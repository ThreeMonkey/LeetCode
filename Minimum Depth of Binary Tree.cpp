/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

����˼·��
1������Ϊ�շ���0

2������û�������������������������+1

3������û�������������������������+1

4�����򣬷���min(����������ȣ�����������ȣ� + 1
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
	int minDepth(TreeNode *root) {
		if (root == NULL) return 0;

		if (root->left == NULL) return minDepth(root->right) + 1;
		else if (root->right == NULL) return minDepth(root->left) + 1;
		else return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};