/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 �� 2
[1,3,5,6], 2 �� 1
[1,3,5,6], 7 �� 4
[1,3,5,6], 0 �� 0
*/
#include <iostream>
using namespace std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		for (int i = 0; i < n; i++) {
			if (A[i] >= target) {
				return i;
			}
		}
		return n;
	}
};

//��������
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if (A == NULL || n == 0) return 0;
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (A[mid] == target) {
				return mid;
			}
			else if (A[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		//�ڽ�����ʱ�����û���ҵ�target����ôleftָ�����target����С������rightָ��С��target����������
		return left;
	}
};