#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (n == 0) {
                return true;
            }
            else if (n == 1) {
                return flowerbed[0] == 0 ? true : false;
            }
            else
                return false;
        }
        for (int i = 0; n > 0 && i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                if (i == 0) {
                    if (flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else if (i == flowerbed.size() - 1) {
                    if (flowerbed[i - 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else{
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
        }
        return n == 0 ? true : false;
    }
};


int main() {
    Solution obj;
    vector<int> v{ 1,0,1,0,0 };
    int n = 2;
    cout<<obj.canPlaceFlowers(v, n);
    return 0;
}