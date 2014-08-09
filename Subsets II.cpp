/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	bool judge(vector<int> &S, int cur, vector<bool> &x) {
		for (int i = 0; i < cur; i++) {
			if (x[i] == false && S[i] == S[cur]) {
				return false;
			}
		}
		return true;
	}
	void DFS(vector<int> &S, int cur, vector<bool> &x, vector<vector<int>> &ans) {
		if (cur == S.size()) {
			//记录解
			vector<int> cur_ans;
			for (int i = 0; i < S.size(); i++) {
				if (x[i] == true) {
					cur_ans.push_back(S[i]);
				}
			}
			ans.push_back(cur_ans);
		}
		else {
			x[cur] = true; //选取当前元素
			if (judge(S, cur, x)) DFS(S, cur + 1, x, ans);

			x[cur] = false; //不选取当前元素
			DFS(S, cur + 1, x, ans);
		}
	}
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<bool> x(S.size(), false);
		vector<vector<int>> ans;
		DFS(S, 0, x, ans);
		return ans;
	}
};