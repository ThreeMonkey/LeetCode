/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

解题思路：
方法一：利用一个长度为32的数组来对每一位上的“1”计数，然后每一位对3取模，剩下的位为1的则对应个数为1的那个数。
方法二：设置int one, two模拟两位二进制来统计各比特位1次数，每当one和two对应二进制位都为1的时候把one和two都清零，
最后剩下的one就是要求的数
*/

class Solution {
public:
	int singleNumber(int A[], int n) {
		int bit1 = 0, bit2 = 0;
		for (int i = 0; i < n; i++) {
			bit2 |= bit1 & A[i];
			bit1 ^= A[i];
			int three = ~(bit1 & bit2);
			bit2 &= three;
			bit1 &= three;
		}
		return bit1;
	}
};