#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main()
{
	int arr[] = { 3,5,7,2,1,4 };
	int length = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, length);
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}