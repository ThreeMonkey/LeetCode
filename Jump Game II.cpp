/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

#include <algorithm>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		int farest = 0;
		int ans = 0;
		int next_pos = 0;
		for (int i = 0; i <= next_pos && i < n - 1; i++) {
			farest = max(farest, i + A[i]);
			if (i == next_pos) {
				ans++;
				next_pos = farest;
			}
		}
		return ans;
	}
};