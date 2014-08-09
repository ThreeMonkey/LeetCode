/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() == 0 || b.length() == 0) return NULL;
		int len_a = a.length() - 1, len_b = b.length() - 1;

		int carry = 0;
		string ans;
		while (len_a >= 0 && len_b >= 0) {
			int sum = (a[len_a] - '0') + (b[len_b] - '0') + carry;
			ans += ((sum % 2) + '0');
			carry = sum / 2;
			len_a--, len_b--;
		}
		while (len_a >= 0) {
			int sum = (a[len_a] - '0') + carry;
			ans += ((sum % 2) + '0');
			carry = sum / 2;
			len_a--;
		}
		while (len_b >= 0) {
			int sum = (b[len_b] - '0') + carry;
			ans += ((sum % 2) + '0');
			carry = sum / 2;
			len_b--;
		}
		if (carry) ans += carry + '0';
		reverse(ans.begin(), ans.end());
		return ans;
	}
};