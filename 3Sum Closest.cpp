/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int ans = 0;
		bool findans = false;
		sort(num.begin(), num.end());
		for (int first = 0; first < num.size(); first++){
			for (int second = first + 1, third = num.size() - 1; second < third;){
				int tmp_sum = num[first] + num[second] + num[third];
				if (tmp_sum < target){
					second++;
				}
				if (tmp_sum > target){
					third--;
				}
				if (tmp_sum == target){
					return tmp_sum;
				}

				if (!findans || (abs(tmp_sum - target) < abs(ans - target))){
					ans = tmp_sum;
					findans = true;
				}
			}
		}
		return ans;
	}
};