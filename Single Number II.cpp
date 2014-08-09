/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

����˼·��
����һ������һ������Ϊ32����������ÿһλ�ϵġ�1��������Ȼ��ÿһλ��3ȡģ��ʣ�µ�λΪ1�����Ӧ����Ϊ1���Ǹ�����
������������int one, twoģ����λ��������ͳ�Ƹ�����λ1������ÿ��one��two��Ӧ������λ��Ϊ1��ʱ���one��two�����㣬
���ʣ�µ�one����Ҫ�����
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