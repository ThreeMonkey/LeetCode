/*
题目：
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

解题思路：
　　进行两遍扫描，第一次从前往后扫描，若后面的child的rating比前面高，则多给一个糖果，
  否则，给他一个糖果。第二遍从后往前扫描，给的糖果数为candy[i] = max(candy[i], candy[i + 1] + 1);
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int candy(vector<int> &ratings) {
		if (ratings.empty()) return 0;

		vector<int> candy(ratings.size());
		candy[0] = 1; //the first children, give he 1 candy
		//从前往后扫描
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) {
				candy[i] = candy[i - 1] + 1;
			}
			else {
				candy[i] = 1;
			}
		}
		//从后向前扫描
		candy[ratings.size() - 1] = max(candy[ratings.size() - 1], 1);
		int ans = candy[ratings.size() - 1];
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) {
				candy[i] = max(candy[i], candy[i + 1] + 1);
			}
			ans += candy[i];
		}
		return ans;
	}
};