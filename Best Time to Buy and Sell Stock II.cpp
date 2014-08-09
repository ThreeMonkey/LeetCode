/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions 
as you like (ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0) {
			return 0;
		}
		int lower = 0, higher = 0;
		int ans = 0;

		for (int i = 1; i < prices.size(); i++){
			if (prices[i] >= prices[higher]){
				higher++;
			}
			else {
				ans += (prices[higher] - prices[lower]);
				lower = i;
				higher = i;
			}
		}
		if (prices[prices.size() - 1] > prices[lower]) {
			ans += (prices[prices.size() - 1] - prices[lower]);
		}
		return ans;

	}
};

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0) return 0;

		int ans = 0;
		for (int i = 1; i < prices.size(); i++) {
			int diff = prices[i] - prices[i - 1];
			if (diff > 0) ans += diff;
		}
		return ans;
	}
};
