/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(int A[], int n) {
		int ans = A[0];
		int cur_ans = 0;
		for (int i = 0; i < n; i++) {
			cur_ans += A[i];
			if (cur_ans < 0) {
				cur_ans = 0;
				ans = max(ans, A[i]);
			}
			else {
				ans = max(ans, cur_ans);
			}
		}
		return ans;
	}
};

// new solution
class Solution {
public:
	int maxSubArray(int A[], int n) {
		int ans = INT_MIN;
		int cur_ans = 0;
		for (int i = 0; i < n; i++) {
			cur_ans = max(cur_ans + A[i], A[i]); // f[j] = max{f[j-1] + A[j], A[j]}
			ans = max(ans, cur_ans);
		}
		return ans;
	}
};

