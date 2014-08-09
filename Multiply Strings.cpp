/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

思路：
	大整数乘法
	1、先将字符串转化为整数数组
	2、计算没一位的乘积
	3、处理进位
*/
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.length() == 0 || num2.length() == 0) return NULL;

		int num1_len = num1.length();
		int num2_len = num2.length();
		vector<int> X, Y; // X is num1; Y is num2
		vector<int> ans;
		for (int i = num1_len - 1; i >= 0; i--) {
			X.push_back(num1[i] - '0');
			ans.push_back(0);
		}
		for (int i = num2_len - 1; i >= 0; i--) {
			Y.push_back(num2[i] - '0');
		}
		int offset = 0;
		for (int i = 0; i < Y.size(); i++) { //Y
			for (int j = 0; j < X.size(); j++) { //X
				if (offset + j < ans.size()) {
					ans[offset + j] += Y[i] * X[j];
				}
				else {
					ans.push_back(Y[i] * X[j]);
				}
			}
			offset += 1;
		}
		int carry = 0;
		for (int i = 0; i < ans.size(); i++) {
			int sum = ans[i] + carry;
			ans[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry) ans.push_back(carry);
		for (int i = ans.size() - 1; i >= 1 && ans[i] == 0; i--, ans.pop_back());
		string result = "";
		for (int i = ans.size() - 1; i >= 0; i--) {
			result += (ans[i] + '0');
		}
		return result;
	}
};