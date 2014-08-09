/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (s == NULL) {
			return 0;
		}
		int ans = 0;
		int begin = -1, end = 0;
		while (s[end] != '\0') end++;
		while (s[--end] == ' ');
		for (int i = 0; i < end; i++) {
			if (s[i] == ' ') {
				begin = i;
			}
		}
		return s[end] == ' ' ? 0 : end - begin;
	}
};