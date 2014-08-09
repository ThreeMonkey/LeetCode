/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ans;
		if (matrix.size() == 0) return ans;
		int rows = matrix.size(), cols = matrix[0].size();
		int total_num = rows * cols;
		int right_start = 0, right_stop = cols - 1;
		int down_start = 1, down_stop = rows - 1;
		int left_start = cols - 2, left_stop = 0;
		int up_start = rows - 2, up_stop = 1;
		int row = 0, col = 0;
		int cnt = 0;
		while (cnt < total_num) {
			//向右走
			for (int i = right_start; i <= right_stop; i++) {
				ans.push_back(matrix[row][col++]);
				cnt++;
			}
			if (cnt >= total_num) break;
			//generate next right_start and right_stop
			right_start = right_start + 1, right_stop = right_stop - 1;
			col--, row++;

			//向下走
			for (int i = down_start; i <= down_stop; i++) {
				ans.push_back(matrix[row++][col]);
				cnt++;
			}
			if (cnt >= total_num) break;
			//generate next down_start and down_stop
			down_start = down_start + 1, down_stop = down_stop - 1;
			row--, col--;

			//向左走
			for (int i = left_start; i >= left_stop; i--) {
				ans.push_back(matrix[row][col--]);
				cnt++;
			}
			if (cnt >= total_num) break;
			//generate next left_start and left_stop
			left_start = left_start - 1, left_stop = left_stop + 1;
			col++, row--;

			//向上走
			for (int i = up_start; i >= up_stop; i--) {
				ans.push_back(matrix[row--][col]);
				cnt++;
			}
			if (cnt >= total_num) break;
			//generate next up_start and up_stop
			up_start = up_start - 1, up_stop = up_stop + 1;
			row++, col++;
		}
		return ans;
	}
};