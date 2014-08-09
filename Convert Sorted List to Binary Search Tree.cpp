/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

解题思路：
注意是让构造平衡二叉搜索树。

每次将链表从中间断开，分成左右两部分。左边部分用来构造左子树，右边部分用来构造右子树。递归进行求解。
*/

#include <iostream>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == NULL) return NULL;

		ListNode *slow = head, *fast = head, *pre = NULL;
		do {
			fast = fast->next;
			if (fast == NULL) break;
			fast = fast->next;

			pre = slow;
			slow = slow->next;
		} while (fast != NULL);

		TreeNode * root = new TreeNode(slow->val);
		if (pre != NULL) {
			pre->next = NULL;
			root->left = sortedListToBST(head);
		}
		else {
			root->left = NULL;
		}
		TreeNode * right_root = sortedListToBST(slow->next);
		root->right = right_root;
		if (pre != NULL) pre->next = slow;
		return root;
	}
};