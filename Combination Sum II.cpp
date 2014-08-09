/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void dfs(vector<int> &num, int begin, int &cur_sum, int target, bool x[], vector<vector<int>> &ans) {
		if (cur_sum >= target || begin == num.size()) {
			if (cur_sum == target) {
				vector<int> cur_ans;
				for (int i = 0; i < num.size(); i++) {
					if (x[i]) cur_ans.push_back(num[i]);
				}
				ans.push_back(cur_ans);
			}
			return;
		}
		else {
			for (int i = begin; i < num.size(); i++) {
				x[i] = true;
				cur_sum += num[i];
				dfs(num, i + 1, cur_sum, target, x, ans);
				cur_sum -= num[i];
				x[i] = false;
				while (i < num.size() - 1 && num[i + 1] == num[i]) i++; //去除重复的解
			}
		}
		return;
	}
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int>> ans;
		bool* x = new bool[num.size()]();
		for (int i = 0; i < num.size(); i++) {
			x[i] = false;
		}
		int cur_sum = 0;
		sort(num.begin(), num.end());
		dfs(num, 0, cur_sum, target, x, ans);
		return ans;
	}
};