#include <bits/stdc++.h>
using namespace std;

// sieve of eratosthenes, O(n*log(log n)) time O(n) space
vector<bool> getSieve(int n){
    vector<bool> sieve(n+1, true); // n+1 because we want to include n also, as we can see in the inner loop we are going till n (n inclusive)
    sieve[0] = sieve[1] = false;
    // we can start from 2 because 0 and 1 are not prime and upto sqrt(n) because after that all numbers will be marked as false by 
    // some other number less than sqrt(n) 
    for(int i=2; i*i<=n; i++){
        if(sieve[i]){
            for(int j=i*i; j<=n; j+=i){ // i*i because all numbers before i*i will be marked as false by some other number less than i
                sieve[j] = false; // mark all multiples of i as false as they are not prime
            }
        }
    }
    return sieve;
}

int main()
{
    int n = 10;
    vector<bool> sieve = getSieve(n);
    int cnt = 0;
    for(int i=0; i<sieve.size(); i++){
        if(sieve[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
