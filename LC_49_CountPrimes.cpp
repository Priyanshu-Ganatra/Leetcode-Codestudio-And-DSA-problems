#include <bits/stdc++.h>
using namespace std;

// sieve of eratosthenes, O(n*log(log n)) time O(n) space
int countPrimes(int n)
{
    if (n == 0)
        return 0;
    vector<bool> prime(n, true); // marking all as prime initially
    prime[0] = prime[1] = false;
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        // only do this for numbers which are not marked non-prime yet, this avoids marking a number as non-prime multiple times, 
        // as a number can be a multiple of multiple numbers
        if (prime[i]) // this works because the inner loop will mark all multiples of i as non-prime and hence they will not be counted and we avoid counting non-prime numbers in the answer
        {
            ans++;
            int j = 2 * i; // stepping by 2*i will give even multiples which are not prime
            // this loop will mark all multiples of i as non-prime
            while (j < n)
            {
                prime[j] = false; // marking multiples of each number as non-prime
                j += i;           // stepping by the number itself will give its further multiples
            }
        }
    }
    return ans;
}

int main()
{
    int n = 10;
    cout << countPrimes(n) << endl;
    return 0;
}
