/*Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
	 The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode*> ans = buildTree(1, n);
		return ans;
	}
	vector<TreeNode *> buildTree(int begin, int end) {
		vector<TreeNode*> sub_ans;
		if (begin > end) {
			sub_ans.push_back(NULL);
			return sub_ans;
		}
		if (begin == end) {
			TreeNode *node = new TreeNode(begin);
			sub_ans.push_back(node);
			return sub_ans;
		}
		for (int i = begin; i <= end; i++) {
			vector<TreeNode *> left_subtree = buildTree(begin, i - 1);
			vector<TreeNode *> right_subtree = buildTree(i + 1, end);

			for (int left = 0; left < left_subtree.size(); left++) {
				for (int right = 0; right < right_subtree.size(); right++) {
					TreeNode *cur_root = new TreeNode(i);
					cur_root->left = left_subtree[left];
					cur_root->right = right_subtree[right];
					sub_ans.push_back(cur_root);
				}
			}
		}
		return sub_ans;
	}
};