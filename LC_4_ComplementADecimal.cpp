#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number to complement: ";
    cin >> n;

    // Optimised solution
    if (n == 0)
    {
        return 1;
    }
    int m = n;
    int mask = 0; // mask is the no. of bits in n
    while (m != 0) // to get the no. of bits in n i.e. no. of iterations required to get the mask value 
    {
        mask = (mask << 1) | 1; // ORing with 1 will set the bit to 1 
        m = m >> 1;
    }
    int ans = (~n) & mask;
    cout << "One's complement: " << ans;

    // TLE wala solution
    // int ans = 0;
    // int i = 0;
    // while (n != 0)
    // {
    //     int last_bit = n & 1;// read last bit i.e. read from right to left (LSB to MSB) i.e. reverse of binary
    //     ans = (last_bit * pow(10, i)) + ans; // reverse no. formula, suppose n = 8 i.e. 1000 in binary
    //     // now we're reading the bits from right to left so this reverse no. formula would give answer in correct form i.e. 0001
    //     // ulta read krr rhe hain hum, phir uska ulta krenge
    //     // ulte ka ulta = seedha

    //     // suppose n(decimal) = 6, binary of 6 = 0110
    //     // 1st iteration: (0 * 0 i.e.(10^0)) + 0 = 0
    //     // 2nd iteration: (1 * 10 i.e.(10^1)) + 0 = 10
    //     // 3rd iteration: (1 * 100 i.e.(10^2)) + 10 = 110
    //     n >>= 1;
    //     i++;
    // }

    // // Now ans variable has equivalent binary no. of n
    // i = 0;
    // int ones_comp = 0;
    // while (ans != 0)
    // {
    //     int last_bit = ans % 10;
    //     ans /= 10;
    //     if (last_bit == 0)
    //     {
    //         ones_comp = (1 * pow(10, i)) + ones_comp;
    //     }
    //     else if(last_bit == 1)
    //     {
    //         ones_comp = (0 * pow(10, i)) + ones_comp;
    //     }
    //     i++;
    // }

    // // Now convert the ones complement binary to equivalent decimal
    // ans = 0;
    // i = 0;
    // while (ones_comp != 0)
    // {
    //     int digit = ones_comp % 10;
    //     ones_comp /= 10;
    //     if (digit == 1)
    //     {
    //         ans += pow(2, i);
    //     }
    //     i++;
    // }
    // cout << "One's complement: " << ans;
}