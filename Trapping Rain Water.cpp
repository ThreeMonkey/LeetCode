/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(int A[], int n) {
		int* left_highest = new int[n];
		int highest = 0;
		for (int i = 0; i < n; i++) {
			highest = max(highest, A[i]);
			left_highest[i] = highest;
		}
		highest = 0;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			highest = max(highest, A[i]);
			int low_highest = min(highest, left_highest[i]);
			ans += max(0, low_highest - A[i]);
		}
		return ans;
	}
};