/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

对于正数A[i]，我们希望它能被放在第i个位置上，这样子当我们找到A[i] != i时，我们就找到了想要的数.
当我们遍历数组的时候，如果我们发现A[i] != i，那么我们就swap(A[A[i]], A[i])，让A[i]放在正确的位置上。
而对于交换之后的A[i]，我们继续做这个操作，直至交换没有意义为止。没有意义表示当前数不是正数，或超过数组长度，或与A[A[i]]相等
最后遍历数组，寻找第一个不符合此要求的元素，返回其下标。
整个过程需要遍历两次数组，复杂度为O(n)。
*/
#include <iostream>
using namespace std;

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		if (A == NULL || n == 0) return 1;
		for (int i = 0; i < n; i++) {
			if (A[i] == i) {
				continue;
			}
			else {
				if (A[i] >= 0 && A[i] < n && A[i] != A[A[i]]) {
					swap(A[i], A[A[i]]);
					i--;
				}
			}
		}
		for (int i = 1; i < n; i++) {
			if (A[i] != i) return i;
		}
		return A[0] == n ? n + 1 : n;
	}
};