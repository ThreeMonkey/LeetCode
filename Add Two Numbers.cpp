/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		ListNode* head = new ListNode((l1->val + l2->val) % 10);
		int carry = (l1->val + l2->val) / 10;
		ListNode* p1 = l1->next, *p2 = l2->next;

		ListNode* cur = head;
		while (p1 != NULL && p2 != NULL) {
			int tmp = p1->val + p2->val + carry;
			cur->next = new ListNode(tmp % 10);
			carry = tmp / 10;
			p1 = p1->next;
			p2 = p2->next;
			cur = cur->next;
		}
		while (p1 != NULL) {
			int tmp = p1->val + 0 + carry;
			cur->next = new ListNode(tmp % 10);
			carry = tmp / 10;
			p1 = p1->next;
			cur = cur->next;
		}
		while (p2 != NULL) {
			int tmp = p2->val + 0 + carry;
			cur->next = new ListNode(tmp % 10);
			carry = tmp / 10;
			p2 = p2->next;
			cur = cur->next;
		}
		if (carry) {
			cur->next = new ListNode(carry);
		}
		return head;
	}
};