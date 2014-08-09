/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [3,2,1].

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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		if (root == NULL) return ans;

		TreeNode *cur = root, *pre = NULL;//pre表示上次输出的节点
		stack<TreeNode *> st;

		while (cur != NULL || !st.empty()) {
			if (cur != NULL) { //根指针进栈，遍历左子树
				st.push(cur);
				cur = cur->left;
			}
			else {
				cur = st.top(); // 取得结点
				if (cur->right == NULL || cur->right == pre) { //如果没有右结点，或者右节点为上次输出的节点，访问该节点
					ans.push_back(cur->val);
					st.pop();
					pre = cur;
					cur = NULL;
				}
				else { //当前时刻，不能访问该节点
					cur = cur->right;
				}
			}
		}
		return ans;
	}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		if (root == NULL) return ans;

		vector<int> left = postorderTraversal(root->left);
		vector<int> right = postorderTraversal(root->right);
		for (int i = 0; i < left.size(); i++) {
			ans.push_back(left[i]);
		}

		for (int i = 0; i < right.size(); i++) {
			ans.push_back(right[i]);
		}

		ans.push_back(root->val);

		return ans;
	}
};