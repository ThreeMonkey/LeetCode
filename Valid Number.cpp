/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

class Solution {
public:
	bool isNumber(const char *s) {
		if (s == NULL || (*s) == '\0') return false;

		int cnt_dot = 0;
		int cnt_e = 0;
		//剔除前后的空格
		const char * tmp = s;
		while (*(tmp + 1) != '\0') {
			if (*tmp == '.') cnt_dot++;
			if (*tmp == 'e') cnt_e++;
			tmp++;
		}
		if (*tmp == '.') cnt_dot++;

		while ((*tmp) == ' ') tmp--;
		if (*tmp == 'e') return false;
		if (*tmp == '+' || *tmp == '-') return false;
		if (*tmp == '.' && cnt_e == 0) tmp--;

		while ((*s) == ' ') s++;
		if (*s == 'e') return false;
		if (*s == '+' || *s == '-') s++;
		if (*s == '.') s++;

		if (cnt_dot > 1 || cnt_e > 1) return false;

		if (s > tmp) return false;

		bool is_valid = true;
		bool e_appeared = false;
		const char* pos = s;
		while (pos <= tmp) {
			if ((*pos) >= '0' && (*pos) <= '9') {
				pos++;
			}
			else if (!e_appeared && (*pos) == '.' && (*(pos + 1) >= '0' && *(pos + 1) <= '9' || *(pos + 1) == 'e') && *(pos - 1) >= '0' && *(pos - 1) <= '9') {
				pos++;
			}
			else if (!e_appeared && (*pos) == 'e' && ((*(pos + 1) >= '0' && *(pos + 1) <= '9')) && ((*(pos - 1) >= '0' && *(pos - 1) <= '9') || (*(pos - 1) == '.' && pos != s))) {
				pos++;
				e_appeared = true;
			}
			else if (!e_appeared && (*pos) == 'e' && (*(pos + 1) == '+' || *(pos + 1) == '-')) {
				pos += 2;
				e_appeared = true;
			}
			else {
				return false;
			}
		}
		return true;
	}
};