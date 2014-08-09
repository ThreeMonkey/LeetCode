/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1        3     3      2      1
\       /     /      / \      \
 3     2     1      1   3      2
/     /       \                 \
2    1         2                 3
*/

class Solution {
public:
	int numTrees(int n) {
		int* f = new int[n + 1];

		f[0] = 1;
		f[1] = 1;

		for (int i = 2; i <= n; i++) { //依次计算长度为i的f值
			f[i] = 0;
			for (int j = i - 1; j >= 0; j--) {
				f[i] += (f[i - 1 - j] * f[j]);
			}
		}
		return f[n];
	}
};