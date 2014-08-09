/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int last = m + n;
		int i, j;
		for (i = m - 1, j = n - 1; i >= 0 && j >= 0;) {
			if (A[i] > B[j]) {
				A[--last] = A[i];
				--i;
			}
			else {
				A[--last] = B[j];
				--j;
			}
		}

		while (i >= 0) A[--last] = A[i--];
		while (j >= 0) A[--last] = B[j--];
	}
};