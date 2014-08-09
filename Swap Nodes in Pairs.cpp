/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
	ListNode *swapPairs(ListNode *head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;

		ListNode *ret_head = head->next;
		ListNode *first = head, *second = head->next, *pre = NULL;
		first->next = second->next;
		second->next = first;
		pre = first;

		first = first ? first->next : NULL;
		second = first ? first->next : NULL;

		while (first != NULL && second != NULL) {
			pre->next = second;
			first->next = second->next;
			second->next = first;
			pre = first;

			first = first ? first->next : NULL;
			second = first ? first->next : NULL;
		}
		return ret_head;
	}
};