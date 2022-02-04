#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int findMaxLength(vector<int>& nums) {
	//brute force approach
	/*int count0 = 0, count1 = 0;
	int max = 0;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i; j < nums.size(); j++) {
			if (nums[j] == 0)
				count0++;
			if (nums[j] == 1)
				count1++;
			if (count0 == count1 && (count0 + count1 > max))
				max = count0 + count1;
		}
		count0 = 0;
		count1 = 0;
	}
	return max;*/
	if (nums.size() <= 1)
		return 0;
	unordered_map<int, int> map;
	int count = nums[0] == 1 ? 1 : -1;
	int _max = 0;
	map[count] = 0;
	map[0] = -1;
	for (int i = 1; i < nums.size(); i++) {
		count = (nums[i] == 1) ? count + 1 : count - 1;	
		if (map.find(count) != map.end()) {
			_max = max(_max, i - map[count]);
		}
		else
			map[count] = i;
	}
	return _max;
}

int main() {
	vector<int> v{ 0,0,1,0,0,0,1,1 };
	cout << findMaxLength(v);
	return 0;
}