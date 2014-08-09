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

		TreeNode *cur = root, *pre = NULL;//pre��ʾ�ϴ�����Ľڵ�
		stack<TreeNode *> st;

		while (cur != NULL || !st.empty()) {
			if (cur != NULL) { //��ָ���ջ������������
				st.push(cur);
				cur = cur->left;
			}
			else {
				cur = st.top(); // ȡ�ý��
				if (cur->right == NULL || cur->right == pre) { //���û���ҽ�㣬�����ҽڵ�Ϊ�ϴ�����Ľڵ㣬���ʸýڵ�
					ans.push_back(cur->val);
					st.pop();
					pre = cur;
					cur = NULL;
				}
				else { //��ǰʱ�̣����ܷ��ʸýڵ�
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