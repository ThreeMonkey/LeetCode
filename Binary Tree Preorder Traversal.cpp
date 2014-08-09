/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

*/
#include <iostream>
#include <vector>
#include <stack>
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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ans;
		stack<TreeNode *> st;
		TreeNode *cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) {
				st.push(cur);
				ans.push_back(cur->val);
				cur = cur->left;
			}
			else {
				cur = st.top(); st.pop();
				cur = cur->right;
			}
		}
		return ans;
	}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		if (root == NULL) {
			return v_preorder;
		}

		v_preorder.push_back(root->val);
		if (root->left) {
			preorderTraversal(root->left);
		}
		if (root->right) {
			preorderTraversal(root->right);
		}

		return v_preorder;
	}
	vector<int> v_preorder;
};