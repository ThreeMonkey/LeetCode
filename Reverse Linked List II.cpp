/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
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

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == NULL) return NULL;

		ListNode *pre_node = NULL, *mid_first = head;
		for (int i = 1; i < m; i++) {
			pre_node = mid_first;
			mid_first = mid_first->next;
		}
		ListNode *last = mid_first->next, *pre = mid_first;
		for (int i = m; i < n; i++) {
			ListNode *tmp = last->next;
			last->next = pre;
			pre = last;
			last = tmp;
		}
		if (pre_node == NULL) {
			head = pre;
			mid_first->next = last;
		}
		else {
			pre_node->next = pre;
			mid_first->next = last;
		}
		return head;
	}
};