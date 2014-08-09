/*
The set [1,2,3,��,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

//һλһλ�㣬ÿһλ����ûʹ�ù��Ľ�С�����֣������ʣ�µ�m��λ���� m!�����з������� k ��ȥ��ֱ��k�����������������
//����һλ����ö�ٵ����������Ҳ��Ϊ���б���
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		int factorial[10];
		factorial[0] = 1;
		for (int i = 1; i < 10; i++) factorial[i] = i * factorial[i - 1];

		bool visited[10];
		memset(visited, false, sizeof(visited));

		string ans;
		for (int i = 1; i <= n; i++) { // for each bit
			for (int j = 1; j <= n; j++) {
				if (!visited[j]) {
					if (k > factorial[n - i]) {
						k -= factorial[n - i];
					}
					else {
						ans += (j + '0');
						visited[j] = true;
						break; //����ѭ��������ѡȡ��һλ
					}
				}
			}
		}
		return ans;
	}
};