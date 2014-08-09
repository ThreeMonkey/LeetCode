/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		if (matrix.empty()) return;
		int rows = matrix.size(), cols = matrix[0].size();

		//利用原矩阵的一行和一列 来保存行和列是否有0，再次遍历数组时查询对应的行和列然后修改值；
		//空间复杂度为O(1)
		int x = -1, y = -1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] == 0) {
					if (x == -1) {
						x = i, y = j;
					}
					else {
						matrix[x][j] = 0;
						matrix[i][y] = 0;
					}
				}
			}
		}
		if (x == -1) return; // 没有0 存在
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if ((matrix[x][j] == 0 || matrix[i][y] == 0) && (i != x && j != y)) {
					matrix[i][j] = 0;
				}
			}
		}
		for (int j = 0; j < cols; j++) matrix[x][j] = 0;
		for (int i = 0; i < rows; i++) matrix[i][y] = 0;
	}
};