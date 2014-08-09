/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

/*假设子串里含有重复字符，则父串一定含有重复字符，单个子问题就可以决定父问题，因此可
以用贪心法。跟动规不同，动规里，单个子问题只能影响父问题，不足以决定父问题。
从左往右扫描，当遇到重复字母时，以上一个重复字母的index + 1，作为新的搜索起始位置，
直到最后一个字母，复杂度是O(n)。*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> site(128, -1);
		int nowstart = -1, ans = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (site[s[i]] >= nowstart)
				nowstart = site[s[i]] + 1;
			site[s[i]] = i;
			ans = max(i - nowstart + 1, ans);
		}
		return ans;
	}
};