/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans;
		int first = -1;
		int second = -1;
		if (A == NULL) {
			ans.push_back(first);
			ans.push_back(second);
			return ans;
		}

		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (A[mid] == target && (mid == 0 || A[mid - 1] != target)) {
				first = mid;
				break;
			}
			else if (A[mid] == target && !(mid == 0 || A[mid - 1] != target)) {
				right = mid - 1;
			}
			else if (A[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		left = 0, right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (A[mid] == target && (mid == n - 1 || A[mid + 1] != target)) {
				second = mid;
				break;
			}
			else if (A[mid] == target && !(mid == n - 1 || A[mid + 1] != target)) {
				left = mid + 1;
			}
			else if (A[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		ans.push_back(first);
		ans.push_back(second);
		return ans;
	}
};