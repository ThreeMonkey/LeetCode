/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence 
of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

����˼·��
ʹ�ö�̬�滮����dp[i][j]��ʾS��ǰi���ַ���T��ǰj���ַ��еĽ⡣

if (S[i - 1] == T[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; //��˼�ǣ������ǰS[i]==T[j]����ô��ǰ�����ĸ�ȿ��Ա���
                                                                      //Ҳ�������������Ա任�������ڱ��������ĸ�ı任��������
																	  //���������ĸ�ı任������

else dp[i][j] = dp[i-1][j]; //�����ǰ�ַ����ȣ���ô��ֻ��������ǰ����ַ�
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int numDistinct(string S, string T) {
		int rows = S.length(), cols = T.length();
		vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
		for (int i = 0; i < rows; i++) {
			dp[i][0] = 1; // if T is empty, every S has 1 match
		}

		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= cols; j++) {
				if (S[i - 1] == T[j - 1]) {
					// have two situation
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[rows][cols];
	}
};