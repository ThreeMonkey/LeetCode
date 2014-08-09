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
			//ֱ�Ӷ���
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


/*����ض���һ���ǰ�����˳�����е�
  ���Ը��ݰ�����˳�����е���һ�����ݣ�ȷ��Ӧ���������߻����Ұ��*/

class Solution {
public:
	bool search_core(int A[], int left, int right, int target) {
		if (left > right) return false;

		int mid = left + (right - left) / 2;

		if (A[mid] == target) return true;

		if (A[left] < A[mid]) { // ��벿������
			if (target >= A[left] && target <= A[mid]) {
				return search_core(A, left, mid - 1, target);
			}
			else {
				return search_core(A, mid + 1, right, target);
			}
		}
		else if (A[mid] < A[left]) { //�Ұ벿������
			if (target >= A[mid] && target <= A[right]) {
				return search_core(A, mid + 1, right, target);
			}
			else {
				return search_core(A, left, mid - 1, target);
			}
		}
		else if (A[mid] == A[left]) {
			if (A[mid] != A[right]) { // �Ұ벿��Ԫ�ز�ͬ�� ������һ��
				return search_core(A, mid + 1, right, target);
			}
			else { // ���� ���߶���Ҫ����
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
