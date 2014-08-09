/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

解题思路：
递归求得左子树的深度left_depth，右子树的深度right_depth，则 ans = max(left_depth, right_depth) + 1;
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
	int maxDepth(TreeNode *root) {
		if (root == NULL){
			return 0;
		}
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		return max(left_depth, right_depth) + 1;

	}
	inline int max(int a, int b) {
		return a > b ? a : b;
	}
};