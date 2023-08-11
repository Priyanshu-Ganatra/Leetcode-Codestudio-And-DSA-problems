#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Enter a number to reverse: ";
    cin >> x;
    int ans = 0;
    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;

        // check for overflow and underflow condition for 32 bit signed integer 
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
        {
            return 0;
        }

        ans = (ans * 10) + digit;
    }
    cout << ans;
}

// Example 1:
// Input: x = 123
// step 1: digit = 123 % 10 = 3
// ans = 0 * 10 + 3 = 3
// step 2: x = 12 % 10 = 2 
// ans = 3 * 10 + 2 = 32
// step 3: x = 1 % 10 = 1
// ans = 32 * 10 + 1 = 321
// Output: 321
