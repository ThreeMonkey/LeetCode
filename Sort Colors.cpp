/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
	int partion(int A[], int low, int high) {
		int pivot = A[low];
		while (low < high) {
			while (low < high && A[high] >= pivot) high--;
			A[low] = A[high];
			while (low < high && A[low] <= pivot) low++;
			A[high] = A[low];
		}
		A[low] = pivot;
		return low;
	}

	void sort(int A[], int start, int end) {
		if (A != NULL && start < end) {
			int pivot_loc = partion(A, start, end);
			sort(A, start, pivot_loc);
			sort(A, pivot_loc + 1, end);
		}
	}
	void sortColors(int A[], int n) {
		sort(A, 0, n - 1);
	}
};