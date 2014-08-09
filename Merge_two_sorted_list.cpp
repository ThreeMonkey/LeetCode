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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL && l2 == NULL) {
			return NULL;
		}
		else if (l1 == NULL) {
			return l2;
		}
		else if (l2 == NULL) {
			return l1;
		}
		else {
			ListNode *p1 = l1, *p2 = l2, *head = NULL, *p = NULL;
			if (p1->val < p2->val) {
				head = p1;
				p1 = p1->next;
			}
			else {
				head = p2;
				p2 = p2->next;
			}

			p = head;
			while (p1 != NULL && p2 != NULL) {
				if (p1->val < p2->val) {
					p->next = p1;
					p = p1;
					p1 = p1->next;
				}
				else {
					p->next = p2;
					p = p2;
					p2 = p2->next;
				}
			}

			if (p1 != NULL) p->next = p1;
			if (p2 != NULL) p->next = p2;

			return head;
		}
		return NULL;
	}
};