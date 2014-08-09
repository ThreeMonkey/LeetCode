/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include <algorithm>
using namespace std;

class Solution {
public:
	int sqrt(int x) {
		if (x == 0) return 0;
		//Å£¶Ùµü´ú, f(ans) = ans^2 - x

		double error = 1e-5;
		double x1 = 1.0;
		while (abs(x1 * x1 - x) > error) {
			x1 = (x1 + x / x1) / 2;
		}
		return int(x1);
	}
};
