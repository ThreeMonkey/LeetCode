/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

// java code
//public class Solution {
//	void GetNext(String needle, int[] next) {
//		int idx = 0, j = -1;
//		next[0] = -1;
//		while (idx < needle.length() - 1) {
//			if (j == -1 || needle.charAt(idx) == needle.charAt(j)) {
//				++idx;
//				++j;
//				next[idx] = j;
//			}
//			else {
//				j = next[j];
//			}
//		}
//	}
//
//	public String strStr(String haystack, String needle) {
//		if (haystack == null || needle == null)
//			return null;
//		if (needle == "") return haystack;
//		if (haystack == "" && needle == "") {
//			return "";
//		}
//
//		int[] next = new int[needle.length()];
//		GetNext(needle, next);
//
//		int i = 0, j = 0;
//		while (i < haystack.length() && j < needle.length()) {
//			if (j == -1 || haystack.charAt(i) == needle.charAt(j)) {
//				++i;
//				++j;
//			}
//			else {
//				j = next[j];
//			}
//		}
//		if (j >= needle.length()) {
//			return haystack.substring(i - needle.length());
//		}
//		else {
//			return null;
//		}
//	}
//}

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		if (haystack == NULL || needle == NULL) return NULL;

		int needle_len = strlen(needle);
		next = new int[needle_len];
		get_next(needle, next);

		int i = 0, j = 0; // haystack[i] , needle[i]
		while (i < strlen(haystack) && j < needle_len) {
			if (j == -1 || haystack[i] == needle[j]) {
				i++, j++;
			}
			else {
				j = next[j];
			}
		}
		if (j >= needle_len) return &haystack[i - needle_len];
		else return NULL;
	}
	void get_next(char* needle, int *next){
		if (next == NULL || strlen(needle) == 0) return;
		next[0] = -1;
		int i = 0, j = -1; // 从needle的第1个字符开始匹配
		while (i < strlen(needle) - 1) {
			if (j == -1 || needle[i] == needle[j]) {
				i++, j++;
				next[i] = j;
			}
			else {
				j = next[j];
			}
		}
	}
private:
	int *next;
};