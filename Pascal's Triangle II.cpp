/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

����˼·��
��������һ��ֱ�ӽ�������Ƕ����������Ȼ�󷵻ص�k�У��������ռ临�ӶȲ������⡣

  ����������ֱ�Ӽ����k�С���k�е�Ԫ��Ϊ Ck0....Ckk
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans;
		ans.push_back(1);

		if (rowIndex == 0) return ans;

		int cur = ans[0];
		for (int i = 1; i <= rowIndex; i++) {
			cur = cur * (double)(rowIndex/*n*/ - i + 1) / i;
			ans.push_back(cur);
		}
		return ans;
	}
};