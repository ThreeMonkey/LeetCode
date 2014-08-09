/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

解题思路：
后序遍历的最后一个元素肯定为根节点；然后在中序遍历的序列中找到该根节点，将中序遍历序列分为左右两部分，对其分别进行递归求解。
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
	TreeNode *buildTreeCore(vector<int> &inorder, int in_begin, int in_end, vector<int> &postorder, int post_begin, int post_end) {
		if (post_begin > post_end || in_begin > in_end) return NULL;

		TreeNode *root = new TreeNode(postorder[post_end]);
		if (post_begin == post_end) {
			return root;
		}
		else {
			int index = findIndex(postorder[post_end], inorder, in_begin, in_end);
			int left_nodes = index - in_begin;
			TreeNode *left_root = buildTreeCore(inorder, in_begin, index - 1, postorder, post_begin, post_begin + left_nodes - 1);
			TreeNode *right_root = buildTreeCore(inorder, index + 1, in_end, postorder, post_begin + left_nodes, post_end - 1);
			root->left = left_root;
			root->right = right_root;
			return root;
		}
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		TreeNode *root = buildTreeCore(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
		return root;
	}
};