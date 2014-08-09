/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

解题思路：
同链表的方法一样。一分为二，递归进行求解。
*/

#include <vector>
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
	TreeNode* BuildTree(vector<int> &num, int start, int end) {
		if (start == end) {
			return NULL;
		}
		int middle = start + (end - start) / 2;
		TreeNode* root = new TreeNode(num[middle]);
		TreeNode* left_child = BuildTree(num, start, middle);
		TreeNode* right_child = BuildTree(num, middle + 1, end);
		root->left = left_child;
		root->right = right_child;
		return root;
	}
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return BuildTree(num, 0, num.size());
	}
};