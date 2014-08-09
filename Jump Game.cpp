/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
	bool canJump(int A[], int n) {
		int farest = 0, next_pos = 0;

		for (int i = 0; i <= next_pos && i < n - 1; i++) {
			farest = max(farest, i + A[i]);
			if (i == next_pos) {
				next_pos = farest;
			}
		}
		return farest >= n - 1;
	}
};