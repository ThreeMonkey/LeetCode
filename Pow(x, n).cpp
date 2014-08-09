/*
Implement pow(x, n).
*/

#include <algorithm>
using namespace std;

class Solution {
public:
	double pow_core(double x, int n) {
		if (n == 0) return 1;
		if (n == 1) return x;
		int half = n >> 1;
		double half_ans = pow(x, half);
		if (n & 1 == 1) {
			return half_ans * half_ans * x;
		}
		else {
			return half_ans * half_ans;
		}
	}
	double pow(double x, int n) {
		bool is_positive = (n >= 0);
		if (is_positive == false) n = abs(n);
		double tmp_ans = pow_core(x, n);
		if (is_positive) {
			return tmp_ans;
		}
		else {
			return 1 / tmp_ans;
		}

	}
};
