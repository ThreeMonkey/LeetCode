/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/

#include <vector>
using namespace std;

class Solution {
public:
	bool judge(vector<bool> counter) {
		bool is_one = false;
		for (int i = 0; i < counter.size(); i++) {
			if (counter[i] == true) {
				is_one = true;
			}
			if (is_one && counter[i] == false) {
				return false;
			}
		}
		return true;
	}
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> ans;
		if (k > n) return ans;

		vector<int> cur_ans;
		vector<bool> counter(n, false);
		for (int i = 0; i < k; i++) {
			counter[i] = true;
			cur_ans.push_back(i + 1);
		}
		ans.push_back(cur_ans);


		do {
			int pos = 0;
			while (pos < n - 1 && !(counter[pos] && !counter[pos + 1])) pos++; //找到第一个10
			if (pos == n - 1) break;
			counter[pos] = false, counter[pos + 1] = true; // change it to 01

			//统计1的个数
			int one_num = 0;
			for (int i = 0; i < pos; i++) {
				if (counter[i]) one_num++;
			}
			//将1移动到左边
			for (int i = 0; i < one_num; i++) {
				counter[i] = true;
			}
			for (int i = one_num; i < pos; i++) {
				counter[i] = false;
			}

			//保存结果
			cur_ans.clear();
			for (int i = 0; i < n; i++) {
				if (counter[i]) {
					cur_ans.push_back(i + 1);
				}
			}
			ans.push_back(cur_ans);

		} while (!judge(counter));

		return ans;
	}
};