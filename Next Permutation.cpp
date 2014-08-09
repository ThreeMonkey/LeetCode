/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		if (num.size() == 1) return;

		int reversed, bigger;
		for (reversed = num.size() - 2; reversed >= 0 && num[reversed] >= num[reversed + 1]; reversed--);
		for (bigger = num.size() - 1; bigger > reversed && num[bigger] <= num[reversed]; bigger--);

		if (reversed < bigger) {
			swap(num[reversed], num[bigger]);
			sort(num.begin() + reversed + 1, num.end());
		}
		else {
			reverse(num.begin(), num.end());
		}
		return;
	}
};