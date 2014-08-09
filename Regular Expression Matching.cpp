/*Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true
*/

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') {
			return *s == '\0';
		}

		if (*(p + 1) == '*') {
			for (const char *str = s; (*str) == *p || (*p == '.') && (*str); str++) {
				if (isMatch(str + 1, p + 2)) {
					return true;
				}
			}
			return isMatch(s, p + 2);
		}
		else {
			return ((*s == *p) || (*p == '.' && *s)) && isMatch(s + 1, p + 1);
		}
	}
};