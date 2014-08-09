/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

#include <algorithm>
using namespace std;
class Solution {
public:
	int x[64];
	bool judge(int t) {
		for (int i = 1; i < t; i++) {
			if (x[i] == x[t] || abs(x[t] - x[i]) == abs(t - i)) {
				return false;
			}
		}
		return true;
	}
	void dfs(int t, int n, int &ans) {
		if (t > n) {
			ans++;
			return;
		}
		else {
			for (int i = 1; i <= n; i++) {
				x[t] = i;
				if (judge(t)) dfs(t + 1, n, ans);
				x[t] = 0;
			}
		}
	}
	int totalNQueens(int n) {
		if (n == 0) return 1;
		int ans = 0;
		//x = new int[n];
		dfs(1, n, ans);
		return ans;
	}
};