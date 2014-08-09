/*
Divide two integers without using multiplication, division and mod operator.
*/
#include <algorithm>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long ans = 0;
		long long long_dividend = dividend;
		long long long_divisor = divisor;
		int is_positive_1 = 1;
		if (dividend < 0) {
			is_positive_1 = -1;
			long_dividend = abs(long_dividend);
		}
		int is_positive_2 = 1;
		if (divisor < 0) {
			is_positive_2 = -1;
			long_divisor = abs(long_divisor);
		}

		while (long_dividend >= long_divisor) {
			long long sum = long_divisor;
			long long cnt = 1;
			while (sum + sum <= long_dividend) {
				sum += sum;
				cnt += cnt;
			}
			long_dividend -= sum;
			ans += cnt;
		}
		return is_positive_1 * is_positive_2 * ans;
	}
};