#include <bits/stdc++.h>
using namespace std;

vector<int> generateFibonacciNumbers(int n)
{
    if (n == 1)
        return {0};
    if (n == 2)
        return {0, 1};

    vector<int> small = generateFibonacciNumbers(n - 1);
    small.push_back(small[n - 2] + small[n - 3]);
    return small;
}

int main()
{
    vector<int> ans = generateFibonacciNumbers(10);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}