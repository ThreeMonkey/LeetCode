/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

#include <vector>
using namespace std;

class Solution {
public:
	void rotate_core(vector<vector<int> > &matrix, int start, int end) {
		if (start >= end) return;

		vector<int> record;
		int idx = 0;
		for (int i = end; i > start; i--) {
			record.push_back(matrix[i][start]);
		}
		for (int i = start; i < end; i++) {
			record.push_back(matrix[start][i]);
			matrix[start][i] = record[idx++];
		}
		for (int i = start; i< end; i++) {
			record.push_back(matrix[i][end]);
			matrix[i][end] = record[idx++];
		}
		for (int i = end; i> start; i--) {
			record.push_back(matrix[end][i]);
			matrix[end][i] = record[idx++];
		}
		for (int i = end; i> start; i--) {
			record.push_back(matrix[i][start]);
			matrix[i][start] = record[idx++];
		}
		rotate_core(matrix, start + 1, end - 1);
	}
	void rotate(vector<vector<int> > &matrix) {
		rotate_core(matrix, 0, matrix.size() - 1);
	}
};