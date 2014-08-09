/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
#include <iostream>
using namespace std;

class Solution {
public:
	bool search_core(int A[], int left, int right, int target) {
		if (left > right) return false;

		bool ans = false;
		int mid = left + (right - left) / 2;

		if (A[left] == A[mid] && A[mid] == A[right]) {
			for (int i = left; i <= right; i++) {
				if (A[i] == target) {
					ans = true;
				}
			}
		}
		else if (A[left] < A[right]) {
			//直接二分
			while (left <= right) {
				mid = left + (right - left) / 2;
				if (A[mid] == target) {
					ans = true;
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
			if (A[mid] == target) {
				ans = true;
			}
			else {
				ans = search_core(A, left, mid - 1, target);
				if (ans == false) ans = search_core(A, mid + 1, right, target);
			}
		}
		return ans;
	}
	bool search(int A[], int n, int target) {
		if (A == NULL) return false;

		return search_core(A, 0, n - 1, target);
	}
};


/*数组必定有一半是按正常顺序排列的
  可以根据按正常顺序排列的那一半数据，确定应该搜索左半边还是右半边*/

class Solution {
public:
	bool search_core(int A[], int left, int right, int target) {
		if (left > right) return false;

		int mid = left + (right - left) / 2;

		if (A[mid] == target) return true;

		if (A[left] < A[mid]) { // 左半部分有序
			if (target >= A[left] && target <= A[mid]) {
				return search_core(A, left, mid - 1, target);
			}
			else {
				return search_core(A, mid + 1, right, target);
			}
		}
		else if (A[mid] < A[left]) { //右半部分有序
			if (target >= A[mid] && target <= A[right]) {
				return search_core(A, mid + 1, right, target);
			}
			else {
				return search_core(A, left, mid - 1, target);
			}
		}
		else if (A[mid] == A[left]) {
			if (A[mid] != A[right]) { // 右半部分元素不同， 搜索那一边
				return search_core(A, mid + 1, right, target);
			}
			else { // 否则， 两边都需要搜索
				bool find = search_core(A, left, mid - 1, target);
				if (!find) {
					find = search_core(A, mid + 1, right, target);
				}
				return find;
			}
		}
		return false;
	}
	bool search(int A[], int n, int target) {
		return search_core(A, 0, n - 1, target);
	}
};
