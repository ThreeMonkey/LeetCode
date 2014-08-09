/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int ans = 0;

		height.push_back(0);// Ìí¼ÓÉÚ±ø

		stack<int> stk;

		int idx = 0;
		while (idx < height.size()) {
			if (stk.empty() || height[idx] >= height[stk.top()]) {
				stk.push(idx++);
			}
			else {
				int t = stk.top(); //current time highest idx
				stk.pop();
				ans = max(ans, height[t] * (stk.empty() ? idx : idx - stk.top() - 1));
			}
		}

		return ans;
	}

	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty()) return 0;

		int rows = matrix.size(), cols = matrix[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));

		//init dp matrix
		for (int j = 0; j < cols; j++) {
			if (matrix[0][j] == '1') {
				dp[0][j] = 1;
			}
		}
		for (int i = 1; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == '1') {
					dp[i][j] = dp[i - 1][j] + 1;
				}
			}
		}

		//caculate
		int ans = 0;
		for (int i = 0; i < rows; i++) {
			int cur_ans = largestRectangleArea(dp[i]);
			ans = max(ans, cur_ans);
		}
		return ans;
	}
};