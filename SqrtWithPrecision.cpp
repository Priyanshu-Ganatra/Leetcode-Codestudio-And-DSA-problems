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

double precisionOfSqrt(int n)
{
    double sqrt = mySqrt(n);
    double step = 0.1;

    int precision = 11;
    for (int i = 0; i < precision; i++)
    {
        double j = sqrt;
        while (j * j <= n)
        {
            sqrt = j;
            j += step;
        }
        step /= 10;
    }

    return sqrt;
}

int main()
{
    int x = 51;
    // cout << precisionOfSqrt(x) << endl;
    printf("%.11f\n", precisionOfSqrt(x));
    return 0;
}