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

int main()
{
    int divisor = -5;
    int divident = 20;
    int ans = getQuotient(abs(divisor), abs(divident));

    if ((divisor < 0 && divident > 0) || (divisor > 0 && divident < 0))
    {
        ans = -ans;
    }
    cout << ans << endl;
    return 0;
}