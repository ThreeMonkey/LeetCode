/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int ans = 0;

		height.push_back(0);// Ìí¼ÓÉÚ±ø

		stack<int> stk;

		int idx = 0;
		while (idx < height.size()) {
			if (stk.empty() || height[idx] >= height[stk.top()]) {
				stk.push(idx++);
			}
			else {
				int t = stk.top(); //current time highest idx
				stk.pop();
				ans = max(ans, height[t] * (stk.empty() ? idx : idx - stk.top() - 1));
			}
		}

		return ans;
	}
};

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int ans = 0;
		vector<int> left(height.size()), right(height.size());
		for (int i = 0; i < height.size(); i++) {
			if (i == 0) {
				left[i] = -1;
			}
			else {
				left[i] = i - 1;
				while (left[i] > -1 && height[left[i]] >= height[i]) {
					left[i] = left[left[i]];
				}
			}
		}

		for (int i = height.size() - 1; i >= 0; i--) {
			if (i == height.size() - 1) {
				right[i] = height.size();
			}
			else {
				right[i] = i + 1;
				while (right[i] < height.size() && height[right[i]] >= height[i]) {
					right[i] = right[right[i]];
				}
			}
			ans = max(ans, (right[i] - left[i] - 1) * height[i]);
		}
		return ans;
	}
};