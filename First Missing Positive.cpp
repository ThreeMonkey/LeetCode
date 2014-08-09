/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

��������A[i]������ϣ�����ܱ����ڵ�i��λ���ϣ������ӵ������ҵ�A[i] != iʱ�����Ǿ��ҵ�����Ҫ����.
�����Ǳ��������ʱ��������Ƿ���A[i] != i����ô���Ǿ�swap(A[A[i]], A[i])����A[i]������ȷ��λ���ϡ�
�����ڽ���֮���A[i]�����Ǽ��������������ֱ������û������Ϊֹ��û�������ʾ��ǰ�������������򳬹����鳤�ȣ�����A[A[i]]���
���������飬Ѱ�ҵ�һ�������ϴ�Ҫ���Ԫ�أ��������±ꡣ
����������Ҫ�����������飬���Ӷ�ΪO(n)��
*/
#include <iostream>
using namespace std;

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		if (A == NULL || n == 0) return 1;
		for (int i = 0; i < n; i++) {
			if (A[i] == i) {
				continue;
			}
			else {
				if (A[i] >= 0 && A[i] < n && A[i] != A[A[i]]) {
					swap(A[i], A[A[i]]);
					i--;
				}
			}
		}
		for (int i = 1; i < n; i++) {
			if (A[i] != i) return i;
		}
		return A[0] == n ? n + 1 : n;
	}
};