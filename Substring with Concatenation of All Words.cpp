/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of 
substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

// Solution 1, O(S * L)
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {  
		map<string, int> words;
		map<string, int> count;
		vector<int> result;
		int wordNum = L.size();
		if (wordNum == 0) return result;
		for (int i = 0; i < wordNum; ++i)
			++words[L[i]];

		int wordSize = L[0].size();
		int slength = S.size();
		for (int i = 0; i <= slength - wordSize*wordNum; ++i)
		{
			count.clear();
			int j = 0;
			for (; j < wordNum; ++j)
			{
				string w = S.substr(i + j*wordSize, wordSize);
				if (words.find(w) == words.end())
					break;
				++count[w];
				if (count[w] > words[w])
					break;
			}
			if (j == wordNum) result.push_back(i);
		}
		return result;
	}
};

// Solution 2, O(S)

// Solution 1, O(S * L)
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> ans;
		unordered_map<string, int> words;
		unordered_map<string, int> cur_words;

		if (L.empty()) return ans;

		int word_len = L[0].length();
		int word_num = L.size();

		// stat
		for (int i = 0; i < word_num; i++) {
			++words[L[i]];
		}

		// find
		for (int i = 0; i < word_len; i++) {
			cur_words.clear();

			int count = 0;
			int index = i;
			for (int j = i; j + word_len <= S.length(); j += word_len) {
				string str = S.substr(j, word_len);
				if (words.count(str)) {
					if (cur_words.count(str)) {
						cur_words[str]++;
					}
					else {
						cur_words[str] = 1;
					}
					if (cur_words[str] <= words[str]) {
						count++;
					}
					else {
						while (cur_words[str] > words[str]) {
							string tmp = S.substr(index, word_len);
							cur_words[tmp] = cur_words[tmp] - 1;
							if (cur_words[tmp] < words[tmp]) {
								count--;
							}
							index += word_len;
						}
					}
					if (count == word_num) {
						ans.push_back(index);
						string tmp = S.substr(index, word_len);
						cur_words[tmp] = cur_words[tmp] - 1;
						count--;
						index += word_len;
					}
				}
				else {
					cur_words.clear();
					count = 0;
					index = j + word_len;
				}
			}
		}
		return ans;
	}
};
