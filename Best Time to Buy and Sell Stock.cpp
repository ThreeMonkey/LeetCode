/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one
share of the stock), design an algorithm to find the maximum profit.
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;

		int ans = 0;
		int max_price = prices[prices.size() - 1];

		for (int i = prices.size() - 1; i >= 0; i--) {
			max_price = max(max_price, prices[i]);
			ans = max(ans, max_price - prices[i]);
		}
		return ans;
	}
};