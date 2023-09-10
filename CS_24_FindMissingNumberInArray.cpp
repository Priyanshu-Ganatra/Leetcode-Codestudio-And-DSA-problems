#include <bits/stdc++.h>
using namespace std;

// suppose n = 5 and array: 1 2 4 5
// then idealXOR = 1 ^ 2 ^ 3 ^ 4 ^ 5 
// and calculatedXOR = 1 ^ 2 ^ 4 ^ 5
// so when we do idealXOR ^ calculatedXOR, every same number will cancel out and we will be left with the missing number

int missingNumber(vector<int> &a, int N)
{
    int idealXOR = 0, calculatedXOR = 0;
    int n = N - 1; // as there is a missing number in the given array
    for (int i = 0; i < n; i++)
    {
        calculatedXOR = calculatedXOR ^ a[i];
        // suppose n = 5, then the loop goes from 0 to 3 and the below line will calculate xor of 1 to 4, so after the
        // loop we xor the idealXOR with 5 to get the idealXOR as 5 was not included in the loop to xor with the other numbers
        idealXOR = idealXOR ^ (i + 1); // as the elements in array start from 1 and not 0 
    }
    idealXOR = idealXOR ^ N;
    return idealXOR ^ calculatedXOR;
}

int main()
{
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    vector<int> a(N - 1);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N - 1; i++)
        cin >> a[i];
    cout << "The missing number is: ";
    cout << missingNumber(a, N) << endl;
    return 0;
}