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

第0行和最后一行中，前一个下标的值和后一个下标的值相差 2 * (nRows - 1) ，以第0行为例，前一个下标为0，
后一个下标为 0+2*4-2=6。
中间行中，前一个下标的值和后一个下标的值需要根据这个下标是该行中的奇数列还是偶数列来计算。以平时的习惯
来计算，因此，行和列的开始值都是0。
以第2行为例，第一个下标是2，后一个下标所处列为1，是奇数列，因此从这个下标到下一个下标相差的值是它们所处
的行i下面的所有行的点的个数，即2 * (nRows - 1 - i)。在这里，nRows-1是为了遵循0下标开始的原则。这样，我们可以
求得这个奇数列的下标为 2+2*(4-1-2)=4。同理，当我们要计算4之后的下标时，我们发现下一个所处的是偶数列2，从这个
下标到下一个下标相差的值其实是它们所处的行i上面的所有行的点的个数，即2 * i。因此，该列的下标计算为4+2*2=8。

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