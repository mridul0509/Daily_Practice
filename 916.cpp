// 916.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int arr[26] = { 0 };
        for (auto i : words2) {
            int temp[26] = { 0 };
            for (auto j : i) {
                temp[j - 'a']++;
                arr[j - 'a'] = max(temp[j - 'a'], arr[j - 'a']);
            }
        }
        vector<string> result;
        for (auto i : words1) {
            int temp[26] = { 0 };
            for (auto j : i) {
                temp[j - 'a']++;
            }
            int flag = 0;
            for (int k = 0; k < 26; k++) {
                if (arr[k] > temp[k]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution *obj = new Solution();
    vector<string> words1{ "amazon","apple","facebook","google","leetcode" };
    vector<string> words2{ "e","o" };
    vector<string> result;
    result = obj->wordSubsets(words1, words2);
    for (auto i : result) {
        cout << i << endl;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
