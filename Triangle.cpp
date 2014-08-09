/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]


The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

解题思路：
从底向上动规，可以减少从上向下动归后找最小值的过程。过程中可以直接修改triangle，而不需要重新开辟空间。
http://www.cnblogs.com/dongguangqing/p/3727861.html
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		for (int i = triangle.size() - 2; i >= 0; i--) {
			for (int j = 0; j < triangle[i].size(); j++) {
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle.empty() ? 0 : triangle[0][0];
	}
};