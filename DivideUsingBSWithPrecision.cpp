#include <bits/stdc++.h>
using namespace std;

// binary search to find quotient
int getQuotient(int divisor, int divident)
{
    int s = 0, e = divident;
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * divisor == divident)
        {
            return mid;
        }
        else if (mid * divisor < divident)
        {
            // right and update ans as we need to find floor value
            ans = mid;
            s = mid + 1;
        }
        else
        {
            // left
            e = mid - 1;
        }
    } 
    return ans;
}

double getQuotientWithPrecision(int divisor, int divident)
{
    double quotient = getQuotient(divisor, divident);
    double step = 0.1;
    int precision = 10;

    for (int i = 0; i < precision; i++)
    {
        double temp = quotient;
        while (temp * divisor < divident)
        {
            quotient = temp;
            temp += step;
        }
        step /= 10;
    }
    return quotient;
}

int main()
{
    int divisor = -3;
    int divident = 571;
    double ans = getQuotientWithPrecision(abs(divisor), abs(divident));

    if ((divisor < 0 && divident > 0) || (divisor > 0 && divident < 0))
    {
        ans = -ans;
    }
    printf("%.10f\n", ans);
    return 0;
}