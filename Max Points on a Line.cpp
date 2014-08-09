/*
����Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

  ����˼·��

  ������һ��Ӧ��ö����������ɵ�ֱ�ߣ�Ȼ�������ĵ��ڲ�������ֱ���ϣ��ڴ˹�����ͳ�����ֵ����˼·�ĸ��Ӷ� O(n^3)

	���ο������ϵ�˼·��ö�ٵ�һ���㣬��unordered_map����¼����ĵ��������б�ʣ���б����ͬ�������Щ����ͬһֱ���ϡ�
	  ����double���⣬��б��ת���ɻ����x��y����ַ�������ע�⴦���ظ��ĵ㣩
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
				/*����б��*/
				int g = gcd(x, y);
				if (g){ /*��ͬһ����*/
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
