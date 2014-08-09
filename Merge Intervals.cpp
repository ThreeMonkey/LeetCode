/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include <vector>
#include <algorithm>
using namespace std;

/**
* Definition for an interval.
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool my_cmp(Interval a, Interval b) {
	if (a.start < b.start) {
		return true;
	}
	else if (a.start == b.start) {
		return a.end < b.end;
	}
	else {
		return false;
	}
}
class Solution {
public:

	vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.size() == 0) return intervals;

		sort(intervals.begin(), intervals.end(), my_cmp);

		vector<Interval> ans;
		Interval cur_ans = intervals[0];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start > cur_ans.end) {
				ans.push_back(cur_ans);
				cur_ans = intervals[i];
			}
			else {
				cur_ans.end = max(cur_ans.end, intervals[i].end);
			}
		}
		ans.push_back(cur_ans);
		return ans;
	}
};