#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> arr1{ 7,2,5,3,5 };
    vector<int> arr2{ 7,2,5,4,6,3,5,3 };

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for (auto i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : arr2)
    {
        cout << i << " ";
    }

    return 0;
}