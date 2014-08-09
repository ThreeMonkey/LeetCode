/*
题目：　
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

解题思路：
　　对每一个数依次进行异或即可得到答案。
*/

class Solution {
public:
	int singleNumber(int A[], int n) {
		int ans = 0;
		for (int i = 0; i < n; i++){
			ans ^= A[i];
		}
		return ans;
	}
};