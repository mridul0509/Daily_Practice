#include <iostream>
#include<vector>

using namespace std;

class Subsequence {
public:

    /* Returns length of longest common subsequence in both the strings. */
    int longestCommonSubsequence(string firstString, string secondString) {

        int firstStringLength = firstString.length();
        int secondStringLength = secondString.length();
        
        /* Initializing a matrix of size (firstStringLength +1)*(secondStringLength+1) 
            with default value 0 for using approach of Dynamic Programming */
        vector<vector<int>> dpMatrix(firstStringLength + 1, vector<int>(secondStringLength + 1, 0));

        /* Followings steps are used to fill the matrix in bottom-up fashion
           The result of longest common subsequence is stored in dpMatrix[firstStringLength][secongStringLength] */
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

        /* string subsequence will store the longest common subsequence */
        string subsequence = "";

        int i = firstStringLength;
        int j = secondStringLength;

        /* Following steps are used to extract the longest common subsequence from the dpMatrix */
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

        /* if the length of subsequence after extraction from dpMatrix is 0 printing appropriate message,
           else printing the longest common subsequence found */
        if (subsequence.length() == 0)
            cout << "No such subsequence" << endl;
        else
            cout << subsequence << endl;

        /* dpMatrix[firstStringLength][secondStringLength] contains the longest common subsequence*/
        return dpMatrix[firstStringLength][secondStringLength];
    }
};


class Sort {
public:
    /* This function takes last element as pivot, places the pivot element at its correct position in sorted array,
       and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
    int partitioning(vector<int>& inputArray, int startingIndex, int endingIndex) {
        int pivot = inputArray[endingIndex]; //pivot element
        int i = startingIndex - 1; //Index of smaller element 
        
        for (int j = startingIndex; j < endingIndex; j++) {
            // If current element is smaller than the pivot
            if (inputArray[j] < pivot) {
                i++;
                int temporaryVariable = inputArray[i];
                inputArray[i] = inputArray[j];
                inputArray[j] = temporaryVariable;
            }
        }
        
        //swapping the pivot to correct index i+1
        int temporaryVariable = inputArray[i+1];
        inputArray[i + 1] = inputArray[endingIndex];
        inputArray[endingIndex] = temporaryVariable;

        return i + 1;
    }

    /* The main function that implements QuickSort
       inputArray --> Array to be sorted,
       startingIndex --> Starting index,
       endingIndex --> Ending index */
    void quickSort(vector<int> &inputArray, int startingIndex, int endingIndex) {
        if (startingIndex < endingIndex) {
            /* pivotElement is partitioning index, inputArray[pivotElement] is now
               at right place */
            int pivotElement = partitioning(inputArray, startingIndex, endingIndex);

            /* Separately sort elements before partition and after partition */
            quickSort(inputArray, startingIndex, pivotElement - 1);
            quickSort(inputArray, pivotElement + 1, endingIndex);
        }
    }

    //function to print the array
    void print(vector<int>& inputArray) {
        for (auto i : inputArray) {
            cout << i << " ";
        }
        cout << endl;
    }
};


// Driver program to test above code
int main()
{

    // to check the Sort class functionality
    vector<int> inputArray{ 2,4,3,7,5,6 };
    Sort* object1 = new Sort();
    int endingIndex = inputArray.size() - 1;
    object1->quickSort(inputArray,0,endingIndex);
    object1->print(inputArray);


    // to check the Subsequence class functionality
    string firstString = "AGGTAB";
    string secondString = "AG";
    Subsequence* obj2 = new Subsequence();
    cout << obj2->longestCommonSubsequence(firstString, secondString);
    return 0;
}
