/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return

[
[5,4,11,2],
[5,8,4,5]
]
解题思路：
简单的DFS
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
	int vec_sum(vector<int> &cur_ans) {
		int sum = 0;
		for (int i = 0; i < cur_ans.size(); i++) {
			sum += cur_ans[i];
		}
		return sum;
	}
	void search_dfs(TreeNode *root, vector<int> &cur_ans, int sum, vector<vector<int>> &ans) {
		if (root->left == NULL && root->right == NULL) {
			cur_ans.push_back(root->val);
			if (vec_sum(cur_ans) == sum) ans.push_back(cur_ans);
			cur_ans.pop_back();
		}
		else {
			cur_ans.push_back(root->val);
			if (root->left != NULL) search_dfs(root->left, cur_ans, sum, ans);
			if (root->right != NULL) search_dfs(root->right, cur_ans, sum, ans);
			cur_ans.pop_back();
		}
		return;
	}
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int>> ans;
		if (root == NULL) return ans;

		vector<int> cur_ans;

		search_dfs(root, cur_ans, sum, ans);
		return ans;
	}
};