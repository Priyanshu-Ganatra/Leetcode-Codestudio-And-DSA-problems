#include <bits/stdc++.h>
using namespace std;

void makeVector(int n, vector<int> &v)
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    makeVector(n/10, v);
    v.push_back(digit);
}

int main()
{
    int n = 54321;
    vector<int> v;
    makeVector(n, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}   