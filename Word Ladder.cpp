/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		typedef pair<string, int> node;
		unordered_set<string> visited; //标识位，避免死循环
		queue<node> q;
		q.push(make_pair(start, 1));
		while (!q.empty()) {
			node cur_node = q.front();
			q.pop();

			if (cur_node.first == end) return cur_node.second;

			for (int i = 0; i < cur_node.first.size(); i++) {
				string tmp = cur_node.first;
				for (char j = 'a'; j <= 'z'; j++) {
					tmp[i] = j; //change one character
					if (tmp == end) return cur_node.second + 1;

					if (dict.count(tmp) && !visited.count(tmp)) {
						q.push(make_pair(tmp, cur_node.second + 1));
						visited.insert(tmp);
					}
				}
			}
		}
		return 0;
	}
};