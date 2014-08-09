/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

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

//一位一位算，每一位优先没使用过的较小的数字，而其后剩下的m个位置有 m!种排列方法，用 k 减去，直到k不大于这个方法数，
//则这一位就是枚举到的这个数。也称为康托编码
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
						break; //跳出循环，继续选取下一位
					}
				}
			}
		}
		return ans;
	}
};