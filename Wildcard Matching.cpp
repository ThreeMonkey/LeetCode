/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false

For each element in s
If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
if there is no *,  return false;
if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.

e.g.

abed
?b*d**

a=?, go on, b=b, go on,
e=*, save * position star=3, save s position ss = 3, p++
e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
d=d, go on, meet the end.
check the rest element in p, if all are *, true, else false;

*/
#include <iostream>
using namespace std;
class Solution {
public:
	bool isMatch(const char *s, const char *p)
	{
		if (s == NULL || p == NULL) return false;
		if (*p == '\0') return *s == '\0';

		int last_s = -1, last_p = -1, i, j;
		for (i = 0, j = 0; s[i] != '\0';) {
			if (s[i] == p[j] || p[j] == '?') i++, j++;
			else if (p[j] == '*') last_p = ++j, last_s = i; // ¼ÙÉè * Æ¥Åä0¸ö×Ö·û
			else if (last_p != -1) i = ++last_s, j = last_p; // »ØÍË
			else return false;
		}

		while (p[j] == '*') j++;
		return !s[i] && !p[j];
	}
};