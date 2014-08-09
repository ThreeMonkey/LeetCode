/*
Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}


Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).


For example,
Given the following perfect binary tree,

1
/  \
2    3
/ \  / \
4  5  6  7


After calling your function, the tree should look like:

1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
解题思路：
　　方法一：直接进行广度优先遍历，在遍历的过程中对next指针赋值。

  　方法二：可以利用生成的next指针来横向扫描，即得到一层的next指针之后，可以利用这一层的next指针来给下一层的next指针赋值。不用考虑连续的空指针，就不用额外实现找下一个子树非空节点，比Populating Next Right Pointers in Each Node II 容易处理。

	代码：
*/
#include <queue>
using namespace std;
/**
* Definition for binary tree with next pointer.
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 方法一
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) {
			return;
		}
		queue<TreeLinkNode*> one;
		queue<TreeLinkNode*> another;

		one.push(root);

		TreeLinkNode* cur;
		TreeLinkNode* next;
		while (!(one.empty() && another.empty())) {
			if (!one.empty()) {
				cur = one.front();
				one.pop();
				if (cur->left != NULL) another.push(cur->left);
				if (cur->right != NULL) another.push(cur->right);
				while (!one.empty()) {
					next = one.front();
					one.pop();
					if (next->left != NULL) another.push(next->left);
					if (next->right != NULL) another.push(next->right);
					cur->next = next;
					cur = next;
				}
				cur->next = NULL;
			}

			if (!another.empty()) {
				cur = another.front();
				another.pop();
				if (cur->left != NULL) one.push(cur->left);
				if (cur->right != NULL) one.push(cur->right);
				while (!another.empty()) {
					next = another.front();
					another.pop();
					if (next->left != NULL) one.push(next->left);
					if (next->right != NULL) one.push(next->right);
					cur->next = next;
					cur = next;
				}
				cur->next = NULL;
			}
		}
	}
};

//方法二
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		TreeLinkNode *head, *nexhead, *last;
		for (head = root; head->left != NULL; head = nexhead)
		{
			nexhead = head->left;
			last = NULL;
			while (head != NULL)
			{
				head->left->next = head->right;
				if (last != NULL) last->right->next = head->left;
				last = head;
				head = head->next;
			}
		}
	}
};