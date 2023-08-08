#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number to check if it's a power of 2: " << endl;
    cin >> n;

    int ans = 1;
    for (int i = 0; i <= 30; i++)
    {

        if (ans == n)
        {
            cout << "Yes";
            return 0;
        }
        if (ans < INT_MAX / 2)
            ans *= 2;
    }
    cout << "No";
    return 0;
}

// Second logic could be to check if the number of set bits in the given number is 1,
// this means the given number is a power of 2 because only 1 bit is set in the binary representation of a power of 2 number
// and all other bits are 0 (0 is not a power of 2) and if we subtract 1 from a power of 2 number, all the bits are set except the
// MSB bit which is 0, so if we do a bitwise AND of a power of 2 number and it's predecessor, the result will be 0, so we can use
// this logic to check if the given number is a power of 2 or not. This logic is implemented in the next snippet.
