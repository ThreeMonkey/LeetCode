/*
Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix :

[
	[1, 3, 5, 7],
	[10, 11, 16, 20],
	[23, 30, 34, 50]
]
Given target = 3, return true.
*/
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.empty()) return false;

		int top_row = 0, top_col = matrix[0].size() - 1;
		while (top_row < matrix.size() && top_col >= 0) {
			if (matrix[top_row][top_col] == target) {
				return true;
			}
			else if (matrix[top_row][top_col] > target) {
				top_col--;
			}
			else {
				top_row++;
			}
		}
		return false;
	}
};