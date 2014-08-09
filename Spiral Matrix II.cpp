/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int>(n));
		int right_start = 0, right_stop = n - 1;
		int down_start = 1, down_stop = n - 1;
		int left_start = n - 2, left_stop = 0;
		int up_start = n - 2, up_stop = 1;
		int cnt = 1, total_num = n * n;
		int col = 0, row = 0;
		while (cnt <= total_num) {
			//向右走
			for (int i = right_start; i <= right_stop; i++) {
				ans[row][col++] = cnt++;
			}
			if (cnt > total_num) break;
			//generate next right_start and right_stop
			right_start = right_start + 1, right_stop = right_stop - 1;
			row++, col--;

			//向下走
			for (int i = down_start; i <= down_stop; i++) {
				ans[row++][col] = cnt++;
			}
			if (cnt > total_num) break;
			//generate next down_start and down_stop
			down_start = down_start + 1, down_stop = down_stop - 1;
			row--, col--;

			//向左走
			for (int i = left_start; i >= left_stop; i--) {
				ans[row][col--] = cnt++;
			}
			if (cnt > total_num) break;
			//generate next left_start and left_stop
			left_start = left_start - 1, left_stop = left_stop + 1;
			col++, row--;

			//向上走
			for (int i = up_start; i >= up_stop; i--) {
				ans[row--][col] = cnt++;
			}
			if (cnt > total_num) break;
			//generate next up_start, up_stop
			up_start = up_start - 1, up_stop = up_stop + 1;
			row++, col++;
		}
		return ans;
	}
};