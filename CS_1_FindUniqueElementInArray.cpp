#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // if we xor A with 0, the answer is A
    // if we xor a number by itself, the answer is 0
    int arr[] = {1, 1, 6, 2, 2};
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans;
} 