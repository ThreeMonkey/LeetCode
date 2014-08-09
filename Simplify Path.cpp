/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> stk;
		if (path[path.length() - 1] != '/') path += '/'; //加入哨兵
		int start_pos = 0, stop_pos = 0;
		for (int i = 0; i < path.length(); i++) {
			if (path[i] == '/') {
				// 解析 每个 /  / 之间的内容
				stop_pos = i - 1;
				string item;
				for (int j = start_pos; j <= stop_pos; j++) {
					item += path[j];
				}

				// 根据 /  /之间的字符串内容，作相应的操作
				if (!item.empty()) {
					if (item == "..") {
						if (!stk.empty()) stk.pop_back();
					}
					else if (item != ".") {
						stk.push_back(item);
					}
				}
				start_pos = i + 1; // 下一个 /  / 的起始坐标
			}
		}
		string ans;
		for (int i = 0; i < stk.size(); i++) {
			ans += ("/" + stk[i]);
		}
		if (ans.empty()) ans += "/";
		return ans;
	}
};