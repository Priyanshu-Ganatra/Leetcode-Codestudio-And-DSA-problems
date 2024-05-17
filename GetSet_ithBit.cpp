#include <bits/stdc++.h>
using namespace std;

int getithBit(int n, int i){
    int mask = (1 << i-1);
    return (n & mask) == 0 ? 0 : 1;
}

int setithBit(int n, int i){
    int mask = (1 << i-1);
    return n | mask;
}

int clearithBit(int n, int i){
    int mask = ~(1 << i-1);
    return n & mask;
}

void updateithBit(int n, int i, int v){
    // v can be 0 or 1
    clearithBit(n, i);
    int mask = (v << i-1);
    n = n | mask;
    cout << "Updated number is " << n << "\n";
}

int main(){
    int n = 10, i = 2;
    cout << "Bit no. " << i << " from the right for the number "  << n << " is " << getithBit(n, i) << "\n";
    i = 1;
    cout << "Setting bit no. " << i << " from the right for the number "  << n << " gives " << setithBit(n, i) << "\n";
    cout << "Clearing bit no. " << i << " from the right for the number "  << n << " gives " << clearithBit(n, i) << "\n";
    updateithBit(n, i, 1);
    return 0;
}