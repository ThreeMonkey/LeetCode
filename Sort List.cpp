/*
��Sort a linked list in O(n log n) time using constant space complexity.

 ����˼·��

 �������Ӷ�ΪO(n* logn) �������㷨�У��������򡢶����򡢹鲢���򡣶��������������ݽṹ��ʹ�ù鲢����ȽϿ��ס�
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

		/*�ҵ������м��Ԫ��*/
		ListNode* p_middle = head;
		ListNode* p_last = head->next;
		while (p_last != NULL && p_last->next != NULL){
			p_middle = p_middle->next;
			p_last = p_last->next->next;
		}

		/*����Ϊ����������*/
		ListNode* p_left = head;
		ListNode* p_right = p_middle->next;
		p_middle->next = NULL;

		/*�����������ֱַ��������*/
		p_left = sortList(p_left);
		p_right = sortList(p_right);

		/*�ϲ�*/
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