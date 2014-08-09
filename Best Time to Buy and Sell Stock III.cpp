/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		/* ǰ׺pre[i]���� 0 ~ i ����һ�����Ž⣬��׺suf[i]���� i ~ prices.size() - 1 ����һ�����Ž⡣
		����λ��pre[i] + suf[i]���ֵΪ��O(n)��
		�������Ž��ʱ����ά��ǰ����׺prices��С����ֵ���뵱ǰprices������ǰ����׺���Ž�Ƚ�ȡ���ţ�O(n)��
		�ܸ��Ӷ�O(n)��*/
		int min_price = 0x7fffffff;
		vector<int> pre(prices.size()), suf(prices.size());
		for (int i = 0; i < prices.size(); i++) {
			min_price = min(min_price, prices[i]);
			pre[i] = max(prices[i] - min_price, i ? pre[i - 1] : 0);
		}
		int max_price = 0x80000000;
		for (int i = prices.size() - 1; i >= 0; i--) {
			max_price = max(max_price, prices[i]);
			suf[i] = max(max_price - prices[i], i < prices.size() - 2 ? suf[i + 1] : 0);
		}
		int ans = 0;
		for (int i = 0; i < prices.size(); i++) {
			ans = max(ans, pre[i] + suf[i]);
		}
		return ans;
	}
};