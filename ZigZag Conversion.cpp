/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

��0�к����һ���У�ǰһ���±��ֵ�ͺ�һ���±��ֵ��� 2 * (nRows - 1) ���Ե�0��Ϊ����ǰһ���±�Ϊ0��
��һ���±�Ϊ 0+2*4-2=6��
�м����У�ǰһ���±��ֵ�ͺ�һ���±��ֵ��Ҫ��������±��Ǹ����е������л���ż���������㡣��ƽʱ��ϰ��
�����㣬��ˣ��к��еĿ�ʼֵ����0��
�Ե�2��Ϊ������һ���±���2����һ���±�������Ϊ1���������У���˴�����±굽��һ���±�����ֵ����������
����i����������еĵ�ĸ�������2 * (nRows - 1 - i)�������nRows-1��Ϊ����ѭ0�±꿪ʼ��ԭ�����������ǿ���
�����������е��±�Ϊ 2+2*(4-1-2)=4��ͬ��������Ҫ����4֮����±�ʱ�����Ƿ�����һ����������ż����2�������
�±굽��һ���±�����ֵ��ʵ��������������i����������еĵ�ĸ�������2 * i����ˣ����е��±����Ϊ4+2*2=8��

*/
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows == 1 || s.length() <= nRows) return s;

		string ans;
		for (int i = 0; i < nRows; i++) {
			ans += s[i];
			if (i == 0 || i == nRows - 1) {
				for (int j = i + 2 * (nRows - 1); j < s.length(); j += 2 * (nRows - 1)) {
					ans += s[j];
				}
			}
			else {
				int cur_pos = i;
				for (int j = 1; cur_pos < s.length(); j++) {
					if ((j & 1) && (cur_pos + (2 * (nRows - 1 - i)) < s.length())) {
						ans += s[cur_pos + (2 * (nRows - 1 - i))];
						cur_pos = cur_pos + (2 * (nRows - 1 - i));
					}
					else if ((j & 1) == 0 && (cur_pos + (2 * i)) < s.length()) {
						ans += s[cur_pos + (2 * i)];
						cur_pos = cur_pos + (2 * i);
					}
					else {
						break;
					}
				}
			}
		}
		return ans;
	}
};