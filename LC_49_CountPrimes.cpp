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
        // only do this for numbers which are not marked non-prime yet
        if (prime[i])
        {
            ans++;
            int j = 2 * i;
            while (j < n)
            {
                prime[j] = false; // marking multiples of each number as non-prime
                j += i;           // stepping by the number itself will gives its multiples
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
