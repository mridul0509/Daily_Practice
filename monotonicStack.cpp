#include <iostream>
#include<vector>

using namespace std;

vector<int> monoStack(vector<int> &nums) {
    vector<int> stack;
    for (int i : nums) {
        while (!stack.empty() && stack.back() >= i) {
            stack.pop_back();
        }
        stack.push_back(i);
    }
    return stack;
}

int main()
{
    vector<int> nums{ 3,1,6,2,5,4 };
    vector<int> result = monoStack(nums);
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}
