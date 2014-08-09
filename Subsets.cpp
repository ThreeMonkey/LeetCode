/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void subsetsDFS(vector<int> &S, vector<bool> &x, int cur_pos, vector<vector<int>> &ans) {
		if (cur_pos == x.size()) {
			//保存结果
			vector<int> cur_ans;
			for (int i = 0; i < cur_pos; i++) {
				if (x[i]) {
					cur_ans.push_back(S[i]);
				}
			}
			sort(cur_ans.begin(), cur_ans.end());
			ans.push_back(cur_ans);
		}
		else {
			for (int i = 0; i <= 1; i++) { //选取S[cur_pos] 和不选取 S[cur_pos]两种情况
				x[cur_pos] = i;
				subsetsDFS(S, x, cur_pos + 1, ans);
				x[cur_pos] = false;
			}
		}
		return;
	}
	vector<vector<int> > subsets(vector<int> &S) {
		vector<bool> x(S.size(), false);
		vector<vector<int>> ans;
		subsetsDFS(S, x, 0, ans);
		return ans;
	}
};