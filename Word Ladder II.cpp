/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Node
{
public:
	string str;
	int pace;
	int pre;
	Node(){}
	Node(string s, int pa, int pr)
	{
		str = s;
		pace = pa;
		pre = pr;
	}
};
class Solution {
public:
	vector<vector<string>> ans;
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<Node> q;
		q.push_back(Node(end, 1, -1));
		unordered_map<string, int> dis;
		dis[end] = 1;
		for (int i = 0; i < q.size(); i++)
		{
			Node now = q[i];
			if (dis.count(start) && now.pace >= dis[start]) break;
			for (int j = 0; j < now.str.length(); j++)
			{
				string tmp = now.str;
				for (char c = 'a'; c <= 'z'; c++)
				{
					tmp[j] = c;
					if ((dict.count(tmp) || tmp == start) && (!dis.count(tmp) || dis[tmp] == now.pace + 1))
					{
						dis[tmp] = now.pace + 1;
						q.push_back(Node(tmp, now.pace + 1, i));
					}
				}
			}
		}
		for (int i = q.size() - 1; i >= 0 && q[i].pace == dis[start]; i--)
		{
			if (q[i].str == start)
			{
				vector<string> tmp;
				for (int j = i; j != -1; j = q[j].pre)
					tmp.push_back(q[j].str);
				ans.push_back(tmp);
			}
		}
		return ans;
	}
};