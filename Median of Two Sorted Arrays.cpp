/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findKth(int A[], int m, int B[], int n, int k) {
		if (m > n) return findKth(B, n, A, m, k);

		if (m == 0) return B[k - 1];
		if (n == 0) return A[k - 1];
		if (k == 1) return min(A[0], B[0]);

		int part_a = min(k >> 1, m), part_b = k - part_a;

		if (A[part_a - 1] < B[part_b - 1]) {
			return findKth(A + part_a, m - part_a, B, n, k - part_a);
		}
		else if (A[part_a - 1] > B[part_b - 1]) {
			return findKth(A, m, B + part_b, n - part_b, k - part_b);
		}
		else {
			return A[part_a - 1];
		}
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if ((m + n) & 1) {
			return findKth(A, m, B, n, (m + n) / 2 + 1);
		}
		else {
			return (findKth(A, m, B, n, (m + n) / 2) + findKth(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
		}
	}
};