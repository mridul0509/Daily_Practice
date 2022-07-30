#include<vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> arr{ 1,3,1,3,2,2,3,2,3,3};
    int count = 1;
    int candidate = -1, votes = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (votes == 0) {
            candidate = arr[i];
            votes = 1;
        }
        else {
            if (arr[i] == candidate)
                votes++;
            else
                votes--;
        }
    }
    cout << candidate << endl;
    return 0;
}
