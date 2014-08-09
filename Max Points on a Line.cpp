/*
　　Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

  解题思路：

  　　第一反应：枚举两个点组成的直线，然后看其他的点在不在这条直线上，在此过程中统计最大值。此思路的复杂度 O(n^3)

	　参考了网上的思路：枚举第一个点，用unordered_map来记录其余的点和这个点的斜率，若斜率相同则代表这些点在同一直线上。
	  避免double问题，把斜率转化成化简的x、y组成字符串。（注意处理重复的点）
*/

#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
/**
* Definition for a point.
*/
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int ans = 0;

		vector<Point>::iterator first, second;
		for (first = points.begin(); first != points.end(); first++){
			map<string, int> record_map;
			int same_point = 0, tmp_ans = 0;
			for (second = first + 1; second != points.end(); second++){
				int x = (*second).x - (*first).x, y = (*second).y - (*first).y;
				if (x == 0 && y == 0){
					same_point++;
					continue;
				}
				/*计算斜率*/
				int g = gcd(x, y);
				if (g){ /*非同一个点*/
					x = x / g;
					y = y / g;
				}
				string str_tmp = to_string(x) + " " + to_string(y);
				if (record_map.find(str_tmp) != record_map.end()){
					record_map[str_tmp] += 1;
				}
				else{
					record_map[str_tmp] = 1;
				}
				tmp_ans = max(tmp_ans, record_map[str_tmp]);
			}
			ans = max(tmp_ans + 1 + same_point, ans);
		}

		return ans;
	}
private:
	int gcd(int x, int y){
		if (y){
			return gcd(y, x % y);
		}
		else{
			return x;
		}
	}
};
