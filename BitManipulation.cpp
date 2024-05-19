#include <bits/stdc++.h>
using namespace std;

int getithBit(int n, int i)
{
    int mask = (1 << i - 1);
    return (n & mask) == 0 ? 0 : 1;
}

int setithBit(int n, int i)
{
    int mask = (1 << i - 1);
    return n | mask;
}

int clearithBit(int n, int i)
{
    int mask = ~(1 << i - 1);
    return n & mask;
}

void updateithBit(int n, int i, int v)
{
    // v can be 0 or 1
    clearithBit(n, i);
    int mask = (v << i - 1);
    n = n | mask;
    cout << "Updated number is " << n << "\n";
}

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int clearBitsInRange(int n, int i, int j)
{
    int mask1 = (-1 << i);
    int mask2 = ~(-1 << j);
    int mask = mask1 | mask2;
    return n & mask;
}

int main()
{
    int n = 10, i = 2, j = 3;
    cout << "Bit no. " << i << " from the right for the number " << n << " is " << getithBit(n, i) << "\n";
    i = 1;
    cout << "Setting bit no. " << i << " from the right for the number " << n << " gives " << setithBit(n, i) << "\n";
    cout << "Clearing bit no. " << i << " from the right for the number " << n << " gives " << clearithBit(n, i) << "\n";
    updateithBit(n, i, 1);
    cout << "Number of set bits in " << n << " is " << countSetBits(n) << "\n";
    i = 4;
    // example n = 10 i.e. 1010
    // i and j are counted from the right-hand side so i or j = 1 means the rightmost bit 
    // clear bits from 4 to 3 i.e. 1010 -> 0010, so ans = 2
    cout << "Clearing bits from " << i << " to " << j << " for the number " << n << " gives " << clearBitsInRange(n, i, j) << "\n";
    return 0;
}