/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
解题思路：
直接求解杨辉三角
*/

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> ans;
		if (numRows == 0) return ans;

		vector<int> row_one;
		vector<int> row_two;

		for (int i = 1; i <= numRows; i++) {
			if (i & 1) {
				for (int j = 0; j < i; j++) {
					if (j == 0 || j == i - 1) {
						row_one.push_back(1);
					}
					else {
						row_one.push_back(row_two[j - 1] + row_two[j]);
					}
				}
				row_two.erase(row_two.begin(), row_two.end());
				ans.push_back(row_one);
			}
			else {
				for (int j = 0; j < i; j++) {
					if (j == 0 || j == i - 1) {
						row_two.push_back(1);
					}
					else {
						row_two.push_back(row_one[j - 1] + row_one[j]);
					}
				}
				row_one.erase(row_one.begin(), row_one.end());
				ans.push_back(row_two);
			}
		}

		return ans;
	}
};