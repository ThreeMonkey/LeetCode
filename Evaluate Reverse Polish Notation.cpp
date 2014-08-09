/*
　　Evaluate the value of an arithmetic expression in Reverse Polish Notation.

  Valid operators are +, -, *, /. Each operand may be an integer or another expression.

  　　Some examples:

	["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
	["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

	解题思路：
	　　遇到数字则将其压入栈中，遇到运算符就弹出栈顶的两个元素做相应的运算，然后将运算结果压入栈中。
	  　　最后的结果保存在栈顶。
*/

#include <vector>
#include <stack>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> st;
		int operand_a = 0, operand_b = 0, tmp;
		stringstream ss;
		vector<string>::iterator it;
		for (it = tokens.begin(); it != tokens.end(); it++){
			ss.clear();
			if ((*it) == "+"){
				operand_b = st.top(); st.pop();
				operand_a = st.top(); st.pop();
				st.push(operand_a + operand_b);
			}
			else if ((*it) == "-"){
				operand_b = st.top(); st.pop();
				operand_a = st.top(); st.pop();
				st.push(operand_a - operand_b);
			}
			else if ((*it) == "*"){
				operand_b = st.top(); st.pop();
				operand_a = st.top(); st.pop();
				st.push(operand_a * operand_b);
			}
			else if ((*it) == "/"){
				operand_b = st.top(); st.pop();
				operand_a = st.top(); st.pop();
				st.push(operand_a / operand_b);
			}
			else{
				ss.str(*it);
				ss >> tmp;
				st.push(tmp);
			}
		}
		return st.top();
	}
};