/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.


Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
#include <iostream>
using namespace std;

class Solution {
public:
	bool g_valid;
	int atoi(const char *str) {
		if (str == NULL) return 0;
		long long ans = 0;
		const char *p = str;
		while ((*p) != '\0' && (*p) == ' ') p++;
		bool is_positive = true;
		if ((*p) == '+') {
			is_positive = true;
			p++;
		}
		else if ((*p) == '-') {
			is_positive = false;
			p++;
		}
		g_valid = true;
		while ((*p) != '\0' && (*p) != ' ') {
			if ((*p) >= '0' && (*p) <= '9') {
				ans = ans * 10 + (*p) - '0';
			}
			else {
				g_valid = false;
				break;
			}
			p++;
		}

		if (is_positive && ans <= INT_MAX) {
			return ans;
		}
		else if (is_positive && ans > INT_MAX) {
			return INT_MAX;
		}
		else if (!is_positive && ans <= 2147483648) {
			return -ans;
		}
		else if (!is_positive && ans > 2147483648) {
			return INT_MIN;
		}
		return 0;
	}
};