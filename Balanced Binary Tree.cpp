/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

解题思路：
递归求解，注意在求解过程中需要记录左子树和右子树的高度。
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
	bool judge(TreeNode *node, int &depth) {
		if (node == NULL) {
			depth = 0;
			return true;
		}

		int left_dep, right_dep;
		bool left_is_balanced = judge(node->left, left_dep);
		bool right_is_balanced = judge(node->right, right_dep);

		depth = max(left_dep, right_dep) + 1;

		return left_is_balanced && right_is_balanced && (abs(left_dep - right_dep) < 2);
	}
	bool isBalanced(TreeNode *root) {
		int depth = 0;
		return judge(root, depth);
	}
};