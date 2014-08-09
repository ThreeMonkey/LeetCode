/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int carry = 1;
		for (int last = digits.size() - 1; last >= 0; last--) {
			int tmp = digits[last] + carry;
			digits[last] = tmp % 10;
			carry = tmp / 10;
		}
		if (carry) {
			digits.insert(digits.begin(), carry);
		}
		return digits;
	}
};