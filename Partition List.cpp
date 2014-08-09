/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
	ListNode *partition(ListNode *head, int x) {
		if (head == NULL) return NULL;

		ListNode *ans = new ListNode(0);
		ans->next = head;
		ListNode *first_bigger = head;
		ListNode *pre = ans;
		while (first_bigger != NULL && first_bigger->val < x) {
			first_bigger = first_bigger->next;
			pre = pre->next;
		}
		ListNode *cur = first_bigger, *tmp = pre;
		while (cur != NULL) {
			while (cur != NULL && cur->val >= x) {
				tmp = cur;
				cur = cur->next;
			}
			if (cur == NULL) break;
			tmp->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			pre = cur;
			cur = tmp->next;
		}
		return ans->next;
	}
};
