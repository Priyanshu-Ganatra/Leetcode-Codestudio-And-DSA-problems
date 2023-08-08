#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i = 0;
	int j = 0;
	vector<int> ans;
	vector<int> arr1 = {1, 2, 3, 4};
	vector<int> arr2 = {4, 5};

	while (i < arr1.size() && j < arr2.size())
	{
		if (arr1[i] == arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
		else if (arr1[i] < arr2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	for (auto &it : ans)
	{
		cout << it << ' ';
	}
}