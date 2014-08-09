/*
题目：
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

解题思路：
一、如果从 i 到 j 的时候理论计算气量刚好为负数，则 i ~ j 的加气站都不可以作为起点。

反证一下，从前往后去掉站，如果去掉的站能增加气，即正数，则结果更糟。
如果去掉的站是负数，那么负数如果抵消了之前的正数，则在到 j 之前已经负数了，如果不能抵消之前的正数，那么结果还是更糟。

二、判断是否能成行：一个环的和为非负就可以。

假设环为正， 0 ~ j 刚好为负， j + 1 ~ k 刚好为负数，k + 1 之后为正，则 k + 1 为答案。

也反证一下，k + 1 出发，到gas.size() - 1都为正，则转回来到 j - 1 都会为正。如果到 j 时候为负，则整个环不可能为正，所以
到 j 的时候也为正，剩下的一样。这样就能够成功转一圈。
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