/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X


After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
����˼·��
�����������ϵĽ���˼·���ȴ����ܵġ�O'�������������ܵ����'O'���ɵ����ַ��ţ��磨'#')��
  �ٱ������з��Ű�O����X�������ַ��Ż���O��

  �����������
*/

#include <vector>
using namespace std;

class Solution {
public:
	int m, n;

	void traversal(int x, int y, vector<vector<char>> &board) {
		if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
			board[x][y] = 'Z';
			traversal(x - 1, y, board);
			traversal(x + 1, y, board);
			traversal(x, y - 1, board);
			traversal(x, y + 1, board);
		}
	}

	void solve(vector<vector<char>> &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (board.empty() || board.size() == 0 || board[0].size() == 0) {
			return;
		}
		m = board.size(), n = board[0].size();
		for (int i = 0; i < n; i++) {
			traversal(0, i, board);
			traversal(m - 1, i, board);
		}
		for (int i = 0; i < m; i++) {
			traversal(i, 0, board);
			traversal(i, n - 1, board);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = board[i][j] == 'Z' ? 'O' : 'X';
			}
		}
	}
};