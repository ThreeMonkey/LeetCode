#include <unordered_map>
#include <queue>
using namespace std;

struct Line {
	int key;
	int value;
	int update_cnt;
};

class LRUCache{
public:
	int capacity;
	unordered_map<int, Line> cache;
	queue<Line> q;
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (cache.count(key)) {
			cache[key].update_cnt++;
			q.push(cache[key]);
			return cache[key].value;
		}
		return -1;
	}

	void set(int key, int value) {
		if (cache.count(key)) {
			cache[key].value = value;
			cache[key].update_cnt++;
			q.push(cache[key]);
		}
		else {
			if (cache.size() == capacity) {
				Line tmp;
				while (!q.empty()) {
					tmp = q.front();
					q.pop();

					if (cache.count(tmp.key) && tmp.update_cnt == cache[tmp.key].update_cnt) {
						break;
					}
				}
				cache.erase(cache.find(tmp.key));
				cache[key].key = key;
				cache[key].value = value;
				cache[key].update_cnt = 0;
				q.push(cache[key]);
				return;
			}
			cache[key].key = key;
			cache[key].value = value;
			cache[key].update_cnt = 0;
			q.push(cache[key]);
		}
	}
};