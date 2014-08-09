/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> ans;
		int cur_word = 0;
		int word_cnt = 0, total_len = 0;
		while (cur_word < words.size()) {
			while (cur_word < words.size() && total_len + words[cur_word].size() + 1 <= L) {
				word_cnt += 1;
				total_len = total_len + words[cur_word].size() + 1;
				cur_word += 1;
			}
			if (cur_word == words.size()) {
				string cur_ans;
				for (int i = cur_word - word_cnt; i < cur_word - 1; i++) {
					cur_ans = cur_ans + words[i] + ' ';
				}
				cur_ans += words[cur_word - 1];
				total_len -= 1;
				int remained = L - total_len;
				for (int i = 1; i <= remained; i++) {
					cur_ans += ' ';
				}
				ans.push_back(cur_ans);
			}
			else if (cur_word < words.size() && total_len + words[cur_word].size() == L) {
				word_cnt += 1; cur_word += 1;
				string cur_ans;
				for (int i = cur_word - word_cnt; i < cur_word - 1; i++) {
					cur_ans = cur_ans + words[i] + ' ';
				}
				cur_ans += words[cur_word - 1];
				ans.push_back(cur_ans);
			}
			else {
				total_len -= 1;
				if (word_cnt == 1) {
					string cur_ans = words[cur_word - 1];
					int remained = L - total_len;
					for (int i = 1; i <= remained; i++) {
						cur_ans += ' ';
					}
					ans.push_back(cur_ans);
				}
				else {
					string cur_ans;
					int remained = L - total_len;
					int mod = remained % (word_cnt - 1);
					int multiple = remained / (word_cnt - 1);
					/*int mod = remained % word_cnt;
					int multiple = remained / word_cnt;*/
					for (int i = cur_word - word_cnt; i < cur_word - 1; i++) {
						cur_ans = cur_ans + words[i];
						for (int j = 1; j <= multiple + 1; j++){
							cur_ans += ' ';
						}
						if (mod) cur_ans += ' ', mod--;
					}
					cur_ans += words[cur_word - 1];
					//cout << cur_ans << endl;
					ans.push_back(cur_ans);
				}

			}
			word_cnt = 0;
			total_len = 0;
		}
		return ans;
	}
};