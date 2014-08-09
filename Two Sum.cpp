/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ans;

		map<int, int> dict; //value:index
		for (int i = 0; i < numbers.size(); i++) {
			dict[numbers[i]] = i;
		}
		for (int i = 0; i < numbers.size(); i++) {
			map<int, int>::iterator it = dict.find(target - numbers[i]);
			if (it != dict.end() && (*it).second != i) {
				ans.push_back(i + 1);
				ans.push_back(dict[target - numbers[i]] + 1);
				break;
			}
		}
		return ans;
	}
};