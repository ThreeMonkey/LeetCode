/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool dfs(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited, string &word, int idx) {
		if (idx == word.length() - 1) {
			return true;
		}
		else {
			bool find = false;
			if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[idx + 1]){//向上搜索
				visited[i - 1][j] = true;
				find = dfs(board, i - 1, j, visited, word, idx + 1);
				visited[i - 1][j] = false;
			}

			if (!find && i < board.size() - 1 && !visited[i + 1][j] && board[i + 1][j] == word[idx + 1]) {//向下搜索
				visited[i + 1][j] = true;
				find = dfs(board, i + 1, j, visited, word, idx + 1);
				visited[i + 1][j] = false;
			}

			if (!find && j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[idx + 1]) {//向左搜索
				visited[i][j - 1] = true;
				find = dfs(board, i, j - 1, visited, word, idx + 1);
				visited[i][j - 1] = false;
			}

			if (!find && j < board[0].size() - 1 && !visited[i][j + 1] && board[i][j + 1] == word[idx + 1]) {//向右搜索
				visited[i][j + 1] = true;
				find = dfs(board, i, j + 1, visited, word, idx + 1);
				visited[i][j + 1] = false;
			}
			return find;
		}
	}
	bool exist(vector<vector<char> > &board, string word) {
		if (board.empty() || word.empty()) return false;

		int rows = board.size(), cols = board[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (board[i][j] == word[0]){
					visited[i][j] = true;
					if (dfs(board, i, j, visited, word, 0)) return true;
					visited[i][j] = false;
				}
			}
		}
		return false;
	}
};