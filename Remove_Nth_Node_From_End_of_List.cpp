/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL) return NULL;

		ListNode *pre = head, *slow = head, *quick = head;
		for (int i = 1; i <= n; i++) quick = quick->next;

		while (quick != NULL) {
			pre = slow;
			slow = slow->next;
			quick = quick->next;
		}
		if (slow != head) {
			pre->next = slow->next;
			delete slow;
			slow = NULL;
		}
		else {
			head = slow->next;
			delete slow;
		}
		return head;
	}
};
