/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int>> ans;

		for (int left = 0; left < num.size();) {
			for (int right = num.size() - 1; right > left + 2;) {
				int sum_of_two = num[left] + num[right];

				int ml = left + 1, mr = right - 1;
				while (ml < mr) {
					if (sum_of_two + num[ml] + num[mr] == target) {
						vector<int> cur_ans = { num[left], num[ml], num[mr], num[right] };
						ans.push_back(cur_ans);
						ml++;
						mr--;
					}
					else if (sum_of_two + num[ml] + num[mr] < target) {
						ml++;
					}
					else {
						mr--;
					}
					//È¥ÖØ
					while (ml < mr && (ml != left + 1 && num[ml] == num[ml - 1])) ml++;
					while (ml < mr && (mr != right - 1 && num[mr] == num[mr + 1])) mr--;
				}
				for (right--; right > left + 2 && num[right] == num[right + 1]; right--);
			}
			for (left++; left < num.size() - 3 && num[left] == num[left - 1]; left++);
		}
		return ans;
	}
};