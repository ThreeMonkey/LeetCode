/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (k == 1 || head == NULL || head->next == NULL) return head;

		ListNode *result = new ListNode(0);
		ListNode *p_base = result;
		ListNode *p_cur = result;

		ListNode *p_node = head;
		int cnt = 1;
		while (p_node != NULL) {
			ListNode *tmp = p_node->next;
			p_node->next = p_cur->next;
			p_cur->next = p_node;

			if (cnt == 1) {
				p_base = p_node;
				cnt++;
			}
			else if (cnt < k) {
				cnt++;
			}
			else if (cnt == k) {
				p_cur = p_base;
				cnt = 1;
			}
			p_node = tmp;
		}

		if (cnt < k + 1 && cnt != 1) {
			ListNode *pre = NULL;
			p_node = p_cur->next;
			while (p_node != NULL) {
				ListNode* p_next = p_node->next;

				if (p_next == NULL) {
					p_cur->next = p_node;
				}

				p_node->next = pre;
				pre = p_node;
				p_node = p_next;
			}
		}
		return result->next;
	}
};

//递归的解法

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (k == 1 || head == NULL || head->next == NULL) return head;

		ListNode *next_group = head;
		for (int i = 0; i < k; i++) {
			if (next_group != NULL) {
				next_group = next_group->next;
			}
			else { // 不足k个， 不翻转
				return head;
			}
		}

		// next_group is the head of next group
		// sub_head is the new head of next group after reversion
		ListNode *sub_head = reverseKGroup(next_group, k);

		// 翻转当前的
		ListNode *cur = head, *pre = NULL;
		while (cur != next_group) {
			ListNode *next = cur->next;
			cur->next = pre ? pre : sub_head;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};