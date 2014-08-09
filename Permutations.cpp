/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> permute_core(vector<int> &num, int start, int end) {
		vector<vector<int>> ans;
		if (start == end) {
			vector<int> tmp = { num[start] };
			ans.push_back(tmp);
			return ans;
		}

		for (int i = end; i >= 0; i--) {
			swap(num[end], num[i]);
			vector<vector<int>> sub_ans = permute_core(num, 0, end - 1);
			for (int j = 0; j < sub_ans.size(); j++) {
				vector<int> tmp = sub_ans[j];
				tmp.push_back(num[end]);
				ans.push_back(tmp);
			}
			swap(num[end], num[i]);
		}
		return ans;
	}
	vector<vector<int> > permute(vector<int> &num) {
		return permute_core(num, 0, num.size() - 1);
	}
};