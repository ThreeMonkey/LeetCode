/*
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool judge(int cur, int *x) {
		for (int i = 1; i < cur; i++) {
			if (x[i] == x[cur] || (abs(cur - i) == abs(x[cur] - x[i]))) {
				return false;
			}
		}
		return true;
	}
	void solveNQueensDFS(int n, int cur, vector<vector<string>> &ans, int* x) {
		if (cur > n) {
			vector<string> cur_ans;
			for (int i = 1; i <= n; i++) {
				string cur_row(n, '.');
				cur_row[x[i] - 1] = 'Q';
				cur_ans.push_back(cur_row);
			}
			ans.push_back(cur_ans);
			return;
		}
		else {
			for (int i = 1; i <= n; i++) {
				x[cur] = i;
				if (judge(cur, x)) solveNQueensDFS(n, cur + 1, ans, x);
				x[cur] = 0;
			}
		}
	}
	vector<vector<string> > solveNQueens(int n) {
		int *x = new int[n + 1]();
		vector<vector<string>> ans;
		solveNQueensDFS(n, 1, ans, x);
		return ans;
	}
};