/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;

		int bits = 0;
		for (int tmp = x; tmp > 0; tmp /= 10) bits++;
		for (int high = bits, low = 1; high > low; high--, low++) {
			int high_part = x / (pow(10, high - 1));
			int low_part = low == 1 ? x % (int(pow<int, int>(10, low))) : (x % (int(pow(10, low)))) / (pow(10, low - 1));
			if (high_part != low_part) return false;
			x %= (int(pow(10, high - 1)));
		}
		return true;
	}
};

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;

		int base = 1;
		for (int tmp = x; tmp >= 10; tmp /= 10) base *= 10;
		while (x > 0) {
			int high = x / base;
			int low = x % 10;
			//cout << "high: " << high << "        low: " << low << endl;
			if (high != low) return false;
			x = x % base; // 去掉最高位
			x = x / 10; // 去掉最低位
			base /= 100;
		}
		return true;
	}
};

