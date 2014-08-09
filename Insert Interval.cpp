/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		vector<Interval> ans = merge(intervals);
		return ans;
	}
};


// new solution, complexity O(n)
// 从前往后遍历
// 在开始的一段， 若 intervals[i].end < newInterval.start， 则将intervals[i]直接插入
// 在中间一段， （intervals[i].end > newInterval.start && intervals[i].start > newInterval.end)，合并， 然后插入
// 将最后一段插入

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ans;
		if (intervals.empty()) {
			ans.push_back(newInterval);
			return ans;
		}

		int end_bt_start, start_bt_end; // intervals[i].end > newInterval.start && intervals[i].start
		for (end_bt_start = 0; end_bt_start < intervals.size() && intervals[end_bt_start].end < newInterval.start; end_bt_start++) {
			ans.push_back(intervals[end_bt_start]); // 直接插入
		}
		for (start_bt_end = end_bt_start; start_bt_end < intervals.size() && intervals[start_bt_end].start <= newInterval.end; start_bt_end++) {
			newInterval.start = min(newInterval.start, intervals[start_bt_end].start);
			newInterval.end = max(newInterval.end, intervals[start_bt_end].end);
		}
		ans.push_back(newInterval);
		while (start_bt_end < intervals.size()) {
			ans.push_back(intervals[start_bt_end++]);
		}
		return ans;
	}
};