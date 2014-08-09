/*
题目：
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

解题思路：
用unordered_map来记录数字是否在数组中。 然后枚举每个数，看其相邻的数在不在unorded_map中，相邻的数在数组里的话，
每个数之多访问一次；相邻的数不在数组里的话，枚举会中断。所以设哈希复杂度为O(1)的话，这个方法是严格的O(n)。
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
				//枚举相邻的数，看是否在字典中
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