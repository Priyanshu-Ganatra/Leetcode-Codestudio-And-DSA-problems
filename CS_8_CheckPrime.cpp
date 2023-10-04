#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n == 1)
			return false;
		if (n % i == 0)
		{
			cnt++;
		}
		if (cnt > 1)
			break; // Break early if more than 1 divisor is found
	}
	if (cnt == 1) // A prime number should have exactly 2 divisors: 1 and itself
		return true;
	else
		return false;
}

int main()
{
	int n = 11;
	if (isPrime(n))
	{
		cout << "Prime";
	}
	else
	{
		cout << "Not Prime";
	}
	return 0;
}