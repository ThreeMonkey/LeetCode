/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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

		ListNode *ans = new ListNode(0);
		ListNode *cur = ans;

		ListNode *pre = head, *last = head->next;
		while (last != NULL) {
			while (last != NULL && last->val == pre->val) last = last->next;
			if (last == pre->next) {
				cur->next = pre;
				cur = cur->next;
			}
			if (last == NULL && pre->next != NULL) {
				cur->next = NULL;
			}

			pre = last;
		}
		return ans->next;
	}
};