#include <iostream>
#include <string>
#include <vector>
using namespace std;


void pre_Order(const vector<char>& arr,int &k,int i)
{
	if (i >= arr.size())
	{
		return;
	}
	if (k != 0)
	{
		if (arr[i] != ' ')
		{
			cout << arr[i];
		}
		k--;
	}
	pre_Order(arr, k, 2 * i);
	pre_Order(arr, k, 2 * i+1);
}

int main()
{
	string str;
	getline(cin, str);
	vector<char> arr;
	arr.push_back(' ');
	int k = 0;
	for (char c : str)
	{
		arr.push_back(c);
		k++;
	}
	pre_Order(arr,k,1);
}