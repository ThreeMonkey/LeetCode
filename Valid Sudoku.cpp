/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
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
					if (flag[0][i][x] == true) return false;  //检查行
					flag[0][i][x] = true;

					if (flag[1][j][x] == true) return false;  //检查列
					flag[1][j][x] = true;

					if (flag[2][i / 3 * 3 + j / 3][x] == true) return false;   //检查方格
					flag[2][i / 3 * 3 + j / 3][x] = true;
				}
			}
		}
		return true;
	}
};