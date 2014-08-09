/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

����˼·��
ע�����ù���ƽ�������������

ÿ�ν�������м�Ͽ����ֳ����������֡���߲��������������������ұ߲��������������������ݹ������⡣
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