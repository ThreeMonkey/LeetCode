/*
　Sort a linked list in O(n log n) time using constant space complexity.

 解题思路：

 　　复杂度为O(n* logn) 的排序算法有：快速排序、堆排序、归并排序。对于链表这种数据结构，使用归并排序比较靠谱。
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
	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		/*找到链表中间的元素*/
		ListNode* p_middle = head;
		ListNode* p_last = head->next;
		while (p_last != NULL && p_last->next != NULL){
			p_middle = p_middle->next;
			p_last = p_last->next->next;
		}

		/*划分为左右两部分*/
		ListNode* p_left = head;
		ListNode* p_right = p_middle->next;
		p_middle->next = NULL;

		/*对左右两部分分别进行排序*/
		p_left = sortList(p_left);
		p_right = sortList(p_right);

		/*合并*/
		ListNode* p_head = NULL;
		if (p_left->val < p_right->val){
			p_head = p_left;
			p_left = p_left->next;
		}
		else{
			p_head = p_right;
			p_right = p_right->next;
		}

		ListNode* p_current = p_head;
		while (p_left != NULL && p_right != NULL) {
			if (p_left->val < p_right->val){
				p_current->next = p_left;
				p_left = p_left->next;
			}
			else {
				p_current->next = p_right;
				p_right = p_right->next;
			}
			p_current = p_current->next;
		}
		if (p_left != NULL) p_current->next = p_left;
		if (p_right != NULL) p_current->next = p_right;

		return p_head;
	}
};