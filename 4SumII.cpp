#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> map1;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                map1[nums1[i] + nums2[j]]++;
            }
        }
        int count = 0;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                if (map1.find(-(nums3[i] + nums4[j])) != map1.end()) {
                    count += map1[-(nums3[i] + nums4[j])];
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> a{ 1,2,3,4 };
    vector<int> b{ 1,2,3,4 };
    vector<int> c{ 1,2,3,4 };
    vector<int> d{ 1,2,3,4 };
    Solution obj;
    int e = obj.fourSumCount(a, b, c, d);
}