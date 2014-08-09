/*
Sort a linked list using insertion sort.
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
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		/*找到最小的元素作为表头*/
		ListNode *p_tmp = head;
		int min_val = head->val;

		ListNode *p_current = head->next;
		while (p_current != NULL) {
			if (p_current->val < min_val) {
				p_tmp = p_current;
				min_val = p_current->val;
			}
			p_current = p_current->next;
		}
		p_tmp->val = head->val;
		head->val = min_val;

		////////////////////////////////////////////////////////
		p_current = head->next;
		while (p_current != NULL){
			ListNode *p_next = p_current->next;

			ListNode *p_pos = head; //找插入位置
			while (p_pos != p_current && p_pos->next->val <= p_current->val) p_pos = p_pos->next;

			ListNode *p_pre = head;  // 找前驱
			while (p_pre->next != p_current) p_pre = p_pre->next;

			if (p_pos != p_current) {
				p_pre->next = p_current->next;
				p_current->next = p_pos->next;
				p_pos->next = p_current;
			}

			p_current = p_next;
		}
		return head;
	}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL) return NULL;

		ListNode *head_pre = new ListNode(INT_MIN);
		ListNode *cur = head;
		while (cur != NULL) {
			ListNode *pre = head_pre;
			while (pre != NULL && pre->next != NULL && pre->val <= cur->val && pre->next->val <= cur->val) pre = pre->next;
			ListNode *tmp = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			cur = tmp;
		}
		return head_pre->next;
	}
};