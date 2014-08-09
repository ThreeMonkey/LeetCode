/*
��Ŀ��
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

����˼·��
��unordered_map����¼�����Ƿ��������С� Ȼ��ö��ÿ�������������ڵ����ڲ���unorded_map�У����ڵ�����������Ļ���
ÿ����֮�����һ�Σ����ڵ�������������Ļ���ö�ٻ��жϡ��������ϣ���Ӷ�ΪO(1)�Ļ�������������ϸ��O(n)��
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int, bool> dict;
		//init
		for (int i = 0; i < num.size(); i++) {
			dict[num[i]] = false;
		}

		int ans = 0;
		for (int i = 0; i < num.size(); i++) {
			if (dict[num[i]] == false) {
				int cnt = 0;
				//ö�����ڵ��������Ƿ����ֵ���
				for (int j = num[i]; dict.count(j); j++, cnt++) {
					dict[j] = true;
				}
				for (int j = num[i] - 1; dict.count(j); j--, cnt++) {
					dict[j] = true;
				}
				ans = max(ans, cnt);
			}
		}
		return ans;
	}
};