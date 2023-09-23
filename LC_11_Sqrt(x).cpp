#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    int s = 0, e = x;
    int ans = -1;
    long long mid = 0;

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        // ans found
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            // store ans
            // and & move right
            ans = mid;
            s = mid + 1;
        }
        else
        {
            // move left
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int x = 2147395599;
    cout << mySqrt(x) << endl;
    return 0;
}