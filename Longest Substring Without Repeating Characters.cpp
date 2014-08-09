/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

/*�����Ӵ��ﺬ���ظ��ַ����򸸴�һ�������ظ��ַ�������������Ϳ��Ծ��������⣬��˿�
����̰�ķ��������治ͬ�����������������ֻ��Ӱ�츸���⣬�����Ծ��������⡣
��������ɨ�裬�������ظ���ĸʱ������һ���ظ���ĸ��index + 1����Ϊ�µ�������ʼλ�ã�
ֱ�����һ����ĸ�����Ӷ���O(n)��*/
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