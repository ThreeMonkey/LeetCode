/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/

#include <iostream>
#include <vector>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *merge(vector<ListNode *> &lists, int left, int right) {
		if (left == right) return lists[left];

		int mid = left + (right - left) / 2;
		ListNode *p_left = merge(lists, left, mid);
		ListNode *p_right = merge(lists, mid + 1, right);
		if (p_left == NULL) return p_right;
		if (p_right == NULL) return p_left;
		ListNode *head = NULL, *p_cur = NULL;
		if (p_left->val <= p_right->val) {
			head = p_left;
			p_cur = p_left;
			p_left = p_left->next;
		}
		else {
			head = p_right;
			p_cur = p_right;
			p_right = p_right->next;
		}
		while (p_left != NULL && p_right != NULL) {
			if (p_left->val <= p_right->val) {
				p_cur->next = p_left;
				p_cur = p_left;
				p_left = p_left->next;
			}
			else {
				p_cur->next = p_right;
				p_cur = p_right;
				p_right = p_right->next;
			}
		}
		if (p_left != NULL) p_cur->next = p_left;
		if (p_right != NULL) p_cur->next = p_right;
		return head;
	}
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.size() == 0) return NULL;
		else return merge(lists, 0, lists.size() - 1);

	}
};