/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		if (n == 0) {
			ans.push_back(0);
			return ans;
		}
		if (n == 1) {
			ans.push_back(0);
			ans.push_back(1);
			return ans;
		}
		vector<int> sub_ans = grayCode(n - 1);
		for (int i = 0; i < sub_ans.size(); i++) {
			ans.push_back(sub_ans[i]);
		}
		for (int i = sub_ans.size() - 1; i >= 0; i--) {
			ans.push_back(sub_ans[i] + (1 << (n - 1)));
		}
		return ans;
	}
};