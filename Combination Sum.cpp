/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	int x[100000];
	void dfs(vector<int> &candidates, int begin, int &cur_sum, int target) {
		if (cur_sum >= target) {
			if (cur_sum == target) {
				vector<int> cur_ans;
				for (int i = 0; i < candidates.size(); i++) {
					for (int k = 0; k < x[i]; k++) {

						cur_ans.push_back(candidates[i]);
					}
				}
				ans.push_back(cur_ans);
			}
			return;
		}
		else {
			for (int i = begin; i < candidates.size(); i++) {
				x[i] += 1;
				cur_sum += candidates[i];
				dfs(candidates, i, cur_sum, target);
				cur_sum -= candidates[i];
				x[i] -= 1;
			}
		}
		return;
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		for (int i = 0; i < candidates.size(); i++) {
			x[i] = 0;
		}
		int cur_sum = 0;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, 0, cur_sum, target);
		return ans;
	}
};