/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL) return NULL;
		if (k == 0) return head;

		//find the List length
		ListNode *ptr = head;
		int len = 1;
		while (ptr->next != NULL) ptr = ptr->next, len++;

		k = k % len;

		//find the kth node
		ListNode *cur = head;
		for (int i = 1; i < len - k; i++) {
			cur = cur->next;
		}

		//change pointer
		if (cur->next != NULL) {
			ListNode *ans = cur->next;
			cur->next = NULL;
			ptr->next = head;

			return ans;
		}
		else {
			return head;
		}
	}
};