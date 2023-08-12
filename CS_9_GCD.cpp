#include <bits/stdc++.h>
using namespace std;

int calcGCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
    return a;
}

int main()
{
    int a = 12, b = 18;
    cout << "GCD/HCF of " << a << " & " << b << " is: "<< calcGCD(a, b);
    return 0;
}