/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include <iostream> 
using namespace std;

class Solution {
public:
	int search_core(int A[], int left, int right, int target) {
		if (left > right) return -1;

		int ans = -1;
		if (A[left] <= A[right]) {
			//直接二分
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (A[mid] == target) {
					ans = mid;
					break;
				}
				else if (A[mid] > target) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
		}
		else {
			int mid = left + (right - left) / 2;
			if (A[mid] == target) {
				ans = mid;
			}
			else {
				ans = search_core(A, left, mid - 1, target);
				if (ans == -1) ans = search_core(A, mid + 1, right, target);
			}
		}
		return ans;
	}
	int search(int A[], int n, int target) {
		if (A == NULL) return -1;

		return search_core(A, 0, n - 1, target);
	}
};