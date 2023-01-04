#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
	int key;
	cin >> key;
	int counter = 2;
	bool flag = true;
	int x = 1;
	while (flag) {
		for (int i = 1; x*i < v.size(); i++) {
			v.erase(v.begin() + (x * (i)));
		}
		x++;
		counter++;
		if (v.size() < counter)
			flag = false;
	}
	bool flag1 = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == key)
			flag1 = true;
	}
	if (flag1)
		cout << 1;
	else
		cout << -1;
}