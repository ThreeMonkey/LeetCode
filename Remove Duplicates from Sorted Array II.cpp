/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 2) return n;

		int len = 1; // A[0] is always in result
		int cnt = 1; // 
		for (int i = 1; i < n; i++) {
			if (A[i] == A[i - 1]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			if (cnt <= 2) {
				A[len++] = A[i];
			}
		}
		return len;
	}
};