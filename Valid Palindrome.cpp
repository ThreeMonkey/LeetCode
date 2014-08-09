/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

设置前后两个指针，依次比较，若不相等则表明不是回文串。注意调过不是字母的字
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;
		for (int i = 0, j = s.length() - 1; i <= j; i++, j--) {
			while (i < s.length() && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))) i++;
			while (j >= 0 && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))) j--;
			if (i > j) break;
			if (s[i] != s[j] && s[i] != s[j] + 32 && s[i] + 32 != s[j]) {
				return false;
			}
		}
		return true;
	}
};