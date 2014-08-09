/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1.empty()) return word2.length();
		if (word2.empty()) return word1.length();

		int word1_len = word1.length(), word2_len = word2.length();
		vector<vector<int>> ans(word1_len + 1, vector<int>(word2_len + 1));
		//init
		for (int i = 0; i <= word2_len; i++) {
			ans[0][i] = i;
		}
		for (int i = 0; i <= word1_len; i++) {
			ans[i][0] = i;
		}

		//caculate
		for (int i = 0; i < word1_len; i++) {
			for (int j = 0; j < word2_len; j++) {
				if (word1[i] == word2[j]) {
					ans[i + 1][j + 1] = ans[i][j];
				}
				else {
					ans[i + 1][j + 1] = min(ans[i][j], min(ans[i][j + 1], ans[i + 1][j])) + 1;
				}
			}
		}
		return ans[word1_len][word2_len];
	}
};