/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

����˼·��

����1�������뵽��������DFS���ѣ� ���������ᳬʱ

  ��2������DP+DFS��ӡ��

	����dp[i] ��ʾǰi���ַ�������Ҫ��site[i]��ʾ���� ������ �����˱�

	  ���鷽�̣�if dp[j] == true && s[j+1 .. i] in dict ; then dp [i] = true; { 0 < j < i}
*/
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> DFS(const string &s, vector<int> *site, int ith)
	{
		vector<string> res;
		for (int i = 0; i < site[ith].size(); i++)
		{
			vector<string> tmp;
			string str = s.substr(site[ith][i], ith - site[ith][i]);
			if (site[site[ith][i]].size() == 0)
				res.push_back(str);
			else
			{
				tmp = DFS(s, site, site[ith][i]);
				for (int j = 0; j < tmp.size(); j++)
					res.push_back(tmp[j] + " " + str);
			}
		}
		return res;
	}
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		//DP + print path
		int n = s.length();
		vector<bool> dp(n + 1, false); // dp[i] ��ʾǰi���ַ�������Ҫ��
		vector<int>* site = new vector<int>[n + 1];// ���� ������
		dp[0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] == true && dict.count(s.substr(j, i - j))) {
					dp[i] = true;
					site[i].push_back(j);
				}
			}
		}
		return DFS(s, site, s.length());
	}
};

//���ѣ� ��ʱ
class Solution {
public:
	void search(string s, unordered_set<string> &dict, string cur_ans, vector<string> &ans) {
		if (s.empty()) {
			ans.push_back(cur_ans);
		}
		else {
			for (int len = 1; len <= s.length(); len++) {
				string str = s.substr(0, len);
				if (dict.count(str)) search(s.substr(len), dict, cur_ans + str + ' ', ans);
			}
		}
		return;
	}
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> ans;
		search(s, dict, "", ans);
		return ans;
	}
};
