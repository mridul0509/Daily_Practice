#include<iostream>

using namespace std;

class Solution {
public:
	int myAtoi(string s) {
		int l = s.size();
		bool negative = false;
		int i = 0;
		int result = 0;
		string temp;
		while ((s[i] == ' ') && i < l)
			i++;
		int j = 0;
		while(s[i] == '-' || s[i] == '+') {
			j++;
			i++;
			if (j > 1)
				return result;
		}
		if ( i > 0 && s[i-1] == '-')
			negative = true;
		while ((i < l) && s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
			result = result * 10 + (s[i] - '0');
			if (result > INT_MAX && !negative)
				return INT_MAX;
			if (result*(-1) < INT_MIN)
				return INT_MIN;
			i++;
		}
		if (negative)
			return -1 * result;
		return result;
	}
};

int main() {
	string a = "+-12";
	Solution obj;
	cout<< obj.myAtoi(a);
	return 0;
}