/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

#include <vector>
#include <memory>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		bool flag[3][9][9];
		memset(flag, false, sizeof(flag));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int x = board[i][j] - '1';
					if (flag[0][i][x] == true) return false;
					flag[0][i][x] = true;

					if (flag[1][j][x] == true) return false;
					flag[1][j][x] = true;

					if (flag[2][i / 3 * 3 + j / 3][x] == true) return false;
					flag[2][i / 3 * 3 + j / 3][x] = true;
				}
			}
		}
		return true;
	}

	bool solveSudokuDFS(vector<vector<char> > &board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					for (int k = 1; k <= 9; k++) {
						board[i][j] = k + '0';
						if (isValidSudoku(board) && solveSudokuDFS(board)) {
							return true;
						}
						board[i][j] = '.';
					}
					return false;
				}
			}
		}
		return true;
	}

	void solveSudoku(vector<vector<char> > &board) {
		//use dfs to solve this problem
		solveSudokuDFS(board);
	}
};