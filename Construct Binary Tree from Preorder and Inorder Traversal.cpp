/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

解题思路：
前序遍历序列的第一个元素肯定为根节点；然后再在中序遍历序列中找到该节点，
并以此将中序遍历序列分为左右两部分，然后对左右两部分分别进行递归求解
*/
#include <vector>
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
	int findIndex(int target, vector<int> &inorder, int begin, int end) {
		for (int i = begin; i <= end; i++) {
			if (inorder[i] == target) {
				return i;
			}
		}
		return -1;
	}
	TreeNode *buildTreeCore(vector<int> &preorder, int pre_begin, int pre_end, vector<int> &inorder, int in_begin, int in_end) {
		if (pre_begin > pre_end || in_begin > in_end) return NULL;

		TreeNode *root = new TreeNode(preorder[pre_begin]);
		if (pre_begin == pre_end) {
			return root;
		}
		else {
			int index = findIndex(preorder[pre_begin], inorder, in_begin, in_end);
			int left_nodes = index - in_begin;
			TreeNode *left_root = buildTreeCore(preorder, pre_begin + 1, pre_begin + left_nodes, inorder, in_begin, index - 1);
			TreeNode *right_root = buildTreeCore(preorder, pre_begin + left_nodes + 1, pre_end, inorder, index + 1, in_end);
			root->left = left_root;
			root->right = right_root;
			return root;
		}
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		TreeNode *root = buildTreeCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
		return root;
	}
};