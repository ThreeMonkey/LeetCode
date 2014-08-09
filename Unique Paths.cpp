/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?
*/

#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> ans(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			ans[i][0] = 1;
		}
		for (int j = 0; j < n; j++) {
			ans[0][j] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
			}
		}
		return ans[m - 1][n - 1];
	}
};