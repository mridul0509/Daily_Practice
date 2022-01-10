#include<iostream>
#include<string>
#include <sstream>

using namespace std;


string addBinary(string a, string b)
{
	int carry = 0;
	string res = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i = 0, sum;
	while (i < a.size() || i < b.size())
	{
		sum = carry;
		if (i < a.size()) sum += a[i] - '0';
		if (i < b.size()) sum += b[i] - '0';
		if (sum == 0) carry = 0, res += '0';
		else if (sum == 1)  carry = 0, res += '1';
		else if (sum == 2)carry = 1, res += '0';
		else carry = 1, res += '1';
		i++;
	}
	if (carry == 1)  res += '1';
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	string s1 = "1111";
	string s2 = "0011";
	//int l1 = s1.length();
	//int l2 = s2.length();
	//reverse(s1.begin(), s1.end());
	//reverse(s2.begin(), s2.end());
	//int length = min(l1, l2);
	//while (l1 < l2)
	//{
	//	s1 = s1 + '0';
	//	l1 = s1.length();
	//}
	//while (l2 < l1)
	//{
	//	s2 = s2 + '0';
	//	l2 = s2.length();
	//}
	//string s3 ="";
	//char ch = '0';
	//for (int i = 0; i < l2; i++)
	//{
	//	char ch1 = s1[i];
	//	char ch2 = s2[i];
	//	if (ch1 == '0' || ch2 == '0')
	//	{
	//		if (ch1 == '1' && ch == '0')
	//		{
	//			s3 = s3 + ch1;
	//		}
	//		if (ch2 == '1' && ch == '0')
	//		{
	//			s3 = s3 + ch2;
	//		}
	//		if (ch1 == '1' && ch == '1')
	//		{
	//			s3 = s3 + '0';
	//			ch = '1';
	//		}
	//		if (ch2 == '1' && ch == '1')
	//		{
	//			s3 = s3 + '0';
	//			ch = '1';
	//		}
	//		if (ch1 == '0' && ch2 == '0')
	//		{
	//			s3 = s3 + ch;
	//			ch = '0';
	//		}
	//	}
	//	else
	//	{
	//		if (ch == '1')
	//		{
	//			s3 = s3 + '1';
	//			ch = '1';
	//		}
	//		else
	//		{
	//			s3 = s3 + '0';
	//			ch = '1';
	//		}
	//	}
	//}
	//if (ch == '1')
	//	s3 = s3 + '1';
	//reverse(s3.begin(),s3.end());
	//cout << s3 << endl;
	////cout << s1 << endl << s2 << endl;
	string res = addBinary(s1, s2);
	cout << res << endl;
	return 0;
}