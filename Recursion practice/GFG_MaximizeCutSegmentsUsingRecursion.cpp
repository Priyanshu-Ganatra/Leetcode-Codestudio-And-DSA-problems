#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of cuts.
// this recursive approach gives TLE on GFG, we'll reiterate it in future with DP
int maximizeTheCuts(int n, int x, int y, int z)
{
    // base cases
    if (n == 0)
        return 0; // 0 cuts are required to make 0 length rod
    if (n < 0)
        return INT_MIN; // INT_MIN is returned to avoid the case when (n is not divisible by any of x, y, z)/(n is negative)

    // 1 is added to include the current cut and then we recursively call for the remaining length of the rod
    int option1 = 1 + maximizeTheCuts(n - x, x, y, z);
    int option2 = 1 + maximizeTheCuts(n - y, x, y, z);
    int option3 = 1 + maximizeTheCuts(n - z, x, y, z);

    int finalAns = max(option1, max(option2, option3)); // maximum of the three options is returned
    return finalAns;
}

int main()
{
    int n = 5, x = 1, y = 2, z = 3;
    cout << "Maximum number of cuts: ";
    cout << maximizeTheCuts(n, x, y, z);
    return 0;
}
