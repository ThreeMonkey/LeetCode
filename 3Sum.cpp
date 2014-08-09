/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> ans;
		if (num.empty()) return ans;

		sort(num.begin(), num.end());

		for (int first = 0; first < num.size(); ) {
			int left = first + 1, right = num.size() - 1;
			while (left < right) {
				int sum = num[first] + num[left] + num[right];
				if (sum == 0) {
					vector<int> cur_ans;
					cur_ans.push_back(num[first]); cur_ans.push_back(num[left]); cur_ans.push_back(num[right]);
					ans.push_back(cur_ans);
					left++, right--;
				}
				else if (sum > 0) {
					right--;
				}
				else {
					left++;
				}
				while (left < right && (left != first + 1 && num[left] == num[left - 1])) left++; // delete duplicate triplets
				while (left < right && (right != num.size() - 1 && num[right] == num[right + 1])) right--;// delete duplicate triplets
			}
			for (first++; first < num.size() && num[first] == num[first - 1]; first++);// delete duplicate triplets
		}
		return ans;
	}
};
// java ´úÂë
//public class Solution {
//	public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
//		Arrays.sort(num);
//		ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
//		for (int first = 0; first < num.length;) {
//			int left = first + 1, right = num.length - 1;
//			while (left < right) {
//				int sum = num[first] + num[left] + num[right];
//				if (sum == 0) {
//					ArrayList<Integer> cur_ans = new ArrayList<Integer>();
//					cur_ans.add(num[first]); cur_ans.add(num[left]); cur_ans.add(num[right]);
//					ans.add(cur_ans);
//					left++; right--;
//				}
//				else if (sum > 0) {
//					right--;
//				}
//				else {
//					left++;
//				}
//				while (left < right && (left != first + 1 && num[left] == num[left - 1])) left++; // delete duplicate triplets
//				while (left < right && (right != num.length - 1 && num[right] == num[right + 1])) right--;// delete duplicate triplets
//			}
//			for (first++; first < num.length && num[first] == num[first - 1]; first++);// delete duplicate triplets
//		}
//		return ans;
//	}
//}