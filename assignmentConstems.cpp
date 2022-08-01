#include <iostream>
#include<vector>

using namespace std;

class Subsequence {
public:
    int longestCommonSubsequence(string firstString, string secondString) {
        int firstStringLength = firstString.length();
        int secondStringLength = secondString.length();
        vector<vector<int>> dpMatrix(firstStringLength + 1, vector<int>(secondStringLength + 1, 0));

        for (int i = 1; i <= firstStringLength; i++) {
            for (int j = 1; j <= secondStringLength; j++) {
                if (firstString[i-1] == secondString[j-1]) {
                    dpMatrix[i][j] = 1 + dpMatrix[i - 1][j - 1];
                }
                else {
                    dpMatrix[i][j] = max(dpMatrix[i - 1][j], dpMatrix[i][j - 1]);
                }
            }
        }

        string subsequence = "";

        int i = firstStringLength;
        int j = secondStringLength;

        while (i > 0 && j > 0) {
            if (firstString[i - 1] == secondString[j - 1]) {
                subsequence = firstString[i-1] + subsequence;
                i--;
                j--;
            }
            else if (dpMatrix[i - 1][j] > dpMatrix[i][j - 1])
                i--;
            else
                j--;
        }

        if (subsequence.length() == 0)
            cout << "No such subsequence" << endl;
        else
            cout << subsequence << endl;

        return dpMatrix[firstStringLength][secondStringLength];
    }
};

class Sort {
public:

    int partitioning(vector<int>& inputArray, int startingIndex, int endingIndex) {
        int pivot = inputArray[endingIndex];
        int i = startingIndex - 1;
        for (int j = startingIndex; j < endingIndex; j++) {
            if (inputArray[j] < pivot) {
                i++;
                int temporaryVariable = inputArray[i];
                inputArray[i] = inputArray[j];
                inputArray[j] = temporaryVariable;
            }
        }
        int temporaryVariable = inputArray[i+1];
        inputArray[i + 1] = inputArray[endingIndex];
        inputArray[endingIndex] = temporaryVariable;



        return i + 1;
    }

    void quickSort(vector<int> &inputArray, int startingIndex, int endingIndex) {
        if (startingIndex < endingIndex) {
            int pivotElement = partitioning(inputArray, startingIndex, endingIndex);
            quickSort(inputArray, startingIndex, pivotElement - 1);
            quickSort(inputArray, pivotElement + 1, endingIndex);
        }
    }

    void print(vector<int>& nums) {
        for (auto i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    /*vector<int> nums{ 2,4,3,7,5,6 };
    Sort* object1 = new Sort();
    int endingIndex = nums.size() - 1;
    object1->quickSort(nums,0,endingIndex);
    object1->print(nums);*/

    string firstString = "AGGTAB";
    string secondString = "";
    Subsequence* obj2 = new Subsequence();
    cout << obj2->longestCommonSubsequence(firstString, secondString);
    return 0;
}
