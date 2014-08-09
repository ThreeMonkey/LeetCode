/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
	void reorderList(ListNode *head) {
		if (head == NULL) return;

		//find the last part
		ListNode *mid = head, *last = head;
		while (last != NULL) {
			last = last->next;
			if (last == NULL) break;
			last = last->next;

			mid = mid->next;
		}
		ListNode *right_head = mid->next;
		mid->next = NULL;

		//翻转 右边部分
		ListNode *pre = NULL, *suf = right_head;
		while (suf != NULL) {
			ListNode * tmp = suf->next;
			if (tmp == NULL) {
				right_head = suf;
			}
			suf->next = pre;
			pre = suf;
			suf = tmp;
		}

		//拼接
		ListNode *cur = head;
		while (cur != NULL && right_head != NULL) {
			ListNode *tmp = right_head->next;
			right_head->next = cur->next;
			cur->next = right_head;
			right_head = tmp;
			cur = cur->next->next;
		}
	}
};