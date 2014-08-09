/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.size() == 0 || grid[0].size() == 0) return 0;

		int rows = grid.size();
		int cols = grid[0].size();



		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i == 0 && j != 0) grid[i][j] = grid[i][j - 1] + grid[i][j];
				else if (i != 0 && j == 0) grid[i][j] = grid[i - 1][j] + grid[i][j];
				else if (i != 0 && j != 0) grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
			}
		}

		return grid[rows - 1][cols - 1];
	}
};