/*
��Ŀ��
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

����˼·��
������������ɨ�裬��һ�δ�ǰ����ɨ�裬�������child��rating��ǰ��ߣ�����һ���ǹ���
  ���򣬸���һ���ǹ����ڶ���Ӻ���ǰɨ�裬�����ǹ���Ϊcandy[i] = max(candy[i], candy[i + 1] + 1);
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
		//��ǰ����ɨ��
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) {
				candy[i] = candy[i - 1] + 1;
			}
			else {
				candy[i] = 1;
			}
		}
		//�Ӻ���ǰɨ��
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