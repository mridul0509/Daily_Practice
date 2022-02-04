#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//brute force method
//int maxProfit(vector<int> v)
//{
//	int profit = 0;
//	int max = INT_MIN;
//	for (int i = 0; i < v.size() - 1; i++)
//	{
//		for (int j = i + 1; j < v.size(); j++)
//		{
//			max = v[j] - v[i];
//			if (max > profit)
//				profit = max;
//		}
//	}
//	return profit;
//}

int maxProfit(vector<int> prices)
{
	int min = INT_MAX;
	int profit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		if (min > prices[i])
			min = prices[i];
		int temp = prices[i] - min;
		if (temp > profit)
			profit = temp;
	}
	return profit;
}

int main()
{
	vector<int> v{ 3,2,6,5,0,3 };
	int result = maxProfit(v);
	cout << result << endl;
	return 0;
}