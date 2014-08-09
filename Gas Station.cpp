/*
��Ŀ��
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

����˼·��
һ������� i �� j ��ʱ�����ۼ��������պ�Ϊ�������� i ~ j �ļ���վ����������Ϊ��㡣

��֤һ�£���ǰ����ȥ��վ�����ȥ����վ�������������������������㡣
���ȥ����վ�Ǹ�������ô�������������֮ǰ�����������ڵ� j ֮ǰ�Ѿ������ˣ�������ܵ���֮ǰ����������ô������Ǹ��㡣

�����ж��Ƿ��ܳ��У�һ�����ĺ�Ϊ�Ǹ��Ϳ��ԡ�

���軷Ϊ���� 0 ~ j �պ�Ϊ���� j + 1 ~ k �պ�Ϊ������k + 1 ֮��Ϊ������ k + 1 Ϊ�𰸡�

Ҳ��֤һ�£�k + 1 ��������gas.size() - 1��Ϊ������ת������ j - 1 ����Ϊ��������� j ʱ��Ϊ������������������Ϊ��������
�� j ��ʱ��ҲΪ����ʣ�µ�һ�����������ܹ��ɹ�תһȦ��
*/
#include <vector>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

		int gas_in_car = 0, ans = 0, total_remain_gas = 0;
		for (int i = 0; i < gas.size(); i++) {
			gas_in_car += (gas[i] - cost[i]);
			total_remain_gas += (gas[i] - cost[i]);
			if (gas_in_car < 0) {
				ans = i + 1;
				gas_in_car = 0;
			}
		}
		return total_remain_gas >= 0 ? ans : -1;
	}
};