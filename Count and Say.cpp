/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
class Solution {
public:
	string countAndSay(int n) {
		vector<string> ans;
		ans.push_back("0"); // ans[0] is 0;
		ans.push_back("1");

		for (int i = 2; i <= n; i++) {
			char num = ans[i - 1][0];
			int count = 1;
			if (ans[i - 1].length() == 1) {
				string cur_ans = "1"; //cnt
				cur_ans += num;
				ans.push_back(cur_ans);
			}
			else {
				string tmp = ans[i - 1];
				string cur_ans = "";
				for (int j = 0; j < ans[i - 1].length() - 1; j++) {
					if (num == tmp[j + 1]) {
						count++;
					}
					else {
						char t_cnt = count + '0';
						cur_ans += t_cnt;
						cur_ans += num;
						count = 1;
						num = tmp[j + 1];
					}
				}
				char t_cnt = count + '0';
				cur_ans += t_cnt;
				cur_ans += num;
				ans.push_back(cur_ans);
			}
		}
		return ans[n];
	}
};