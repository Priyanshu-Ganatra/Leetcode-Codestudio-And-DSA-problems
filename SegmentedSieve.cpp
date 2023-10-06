#include <bits/stdc++.h>
using namespace std;

// sieve of eratosthenes, O(n*log(log n)) time O(n) space
vector<bool> getSieve(int n)
{
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

vector<bool> segSieve(int l, int r)
{
    // get primes array, which will be used to mark non-primes in segmented sieve array
    vector<bool> sieve = getSieve(sqrt(r));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }
    vector<bool> segSieve(r-l+1, true);
    if(l == 1 || l == 0){
        segSieve[0] = false;
    } 
    for(auto basePrime: basePrimes){
        int firstMultiple = (l / basePrime) * basePrime;
        if(firstMultiple < l){
            firstMultiple += basePrime;
        }
        int j = max(firstMultiple, basePrime * basePrime);
        while(j <= r){
            segSieve[j - l] = false;
            j += basePrime;
        }
    }
    return segSieve;
}

int main()
{
    int l = 110, r = 130;
    vector<bool> ss = segSieve(l, r);
    for(int i=0; i<ss.size(); i++){
        if(ss[i]){
            cout << i + l << " ";
        }
    }
    cout << endl;
    return 0;
}