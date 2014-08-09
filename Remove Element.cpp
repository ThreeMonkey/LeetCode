/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int cnt = 0;
		int head = 0;
		int tail = n - 1;
		while (head <= tail) {
			if (A[head] == elem) {
				cnt++;
				A[head] = A[tail];
				tail--;
			}
			else {
				head++;
			}
		}
		return n - cnt;
	}
};