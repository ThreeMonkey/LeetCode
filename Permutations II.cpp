/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void permuteUnique_core(vector<int> &num, int start, vector<vector<int>> &ans) {
		if (start == num.size()) {
			ans.push_back(num);
		}
		for (int i = start; i < num.size(); i++) {
			swap(num[start], num[i]);
			permuteUnique_core(num, start + 1, ans);
			swap(num[start], num[i]);
			while (i < num.size() - 1 && num[i + 1] == num[i]) i++;
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int>> ans;
		if (num.size() == 0) return ans;

		vector<vector<int>> tmp_ans;
		sort(num.begin(), num.end());
		permuteUnique_core(num, 0, tmp_ans);
		sort(tmp_ans.begin(), tmp_ans.end());
		for (int i = 0; i < tmp_ans.size(); i++) {
			if (i == 0 || tmp_ans[i] != tmp_ans[i - 1]) {
				ans.push_back(tmp_ans[i]);
			}
		}

		return ans;
	}
};


//解法二， 不需要对结果进行去重

class Solution {
public:
	//从数组的[start,end）范围内寻找元素target
	bool find(vector<int> &num, int start, int end, int target)
	{
		for (int i = start; i < end; i++) {
			if (num[i] == target)
				return true;
		}

		return false;
	}
	void permuteUnique_core(vector<int> &num, int start, vector<vector<int>> &ans) {
		if (start == num.size()) {
			ans.push_back(num);
		}
		for (int i = start; i < num.size(); i++) {
			if (i == start || !find(num, start, i, num[i])) {
				swap(num[start], num[i]);
				permuteUnique_core(num, start + 1, ans);
				swap(num[start], num[i]);
			}
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int>> ans;
		if (num.size() == 0) return ans;

		sort(num.begin(), num.end());
		permuteUnique_core(num, 0, ans);

		return ans;
	}
};