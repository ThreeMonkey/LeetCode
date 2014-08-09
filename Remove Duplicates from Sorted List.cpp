/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* cur = head, *to_be_deleted = NULL;
		while (cur->next != NULL) {
			if (cur->next->val != cur->val) {
				cur = cur->next;
			}
			else { // ÖµÏàÍ¬£¬É¾³ý
				to_be_deleted = cur->next;
				cur->next = cur->next->next;
				delete to_be_deleted;
			}
		}
		return head;
	}
};
