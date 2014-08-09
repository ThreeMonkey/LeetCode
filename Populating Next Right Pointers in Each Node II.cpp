/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.


For example,
Given the following binary tree,

1
/  \
2    3
/ \    \
4   5    7


After calling your function, the tree should look like:

1 -> NULL
/  \
2 -> 3 -> NULL
/ \    \
4-> 5 -> 7 -> NULL
解题思路：
　　方法一：直接进行广度优先遍历，在遍历的过程中对next指针赋值。

  　　方法二：可以利用生成的next指针来横向扫描，即得到一层的next指针之后，可以利用这一层的next指针来给下一层的next指针赋值。
*/

#include <iostream>
using namespace std;

//方法二代码
/**
* Definition for binary tree with next pointer.
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode *findNext(TreeLinkNode *head)
	{
		while (head != NULL && head->left == NULL && head->right == NULL)
			head = head->next;
		return head;
	}
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		TreeLinkNode *head, *last, *nexhead;
		for (head = root; head != NULL; head = nexhead)
		{
			head = findNext(head);
			if (head == NULL) break;
			if (head->left != NULL) nexhead = head->left;
			else nexhead = head->right;
			for (last = NULL; head != NULL; last = head, head = findNext(head->next))
			{
				if (head->left != NULL && head->right != NULL)
					head->left->next = head->right;
				if (last == NULL) continue;
				if (last->right != NULL)
					last->right->next = head->left != NULL ? head->left : head->right;
				else
					last->left->next = head->left != NULL ? head->left : head->right;
			}
		}
	}
};
