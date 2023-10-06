#include <bits/stdc++.h>
using namespace std;

// sieve of eratosthenes, O(n*log(log n)) time O(n) space
vector<bool> getSieve(int n){
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i=2; i*i<=n; i++){
        if(sieve[i]){
            for(int j=i*i; j<=n; j+=i){
                sieve[j] = false;
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
