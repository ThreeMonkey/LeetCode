/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
	int climbStairs(int n) {
		int* step = new int[n + 1];
		step[0] = 1;
		step[1] = 1;
		for (int i = 2; i <= n; i++) {
			step[i] = step[i - 1] + step[i - 2];
		}
		return step[n];
	}
};