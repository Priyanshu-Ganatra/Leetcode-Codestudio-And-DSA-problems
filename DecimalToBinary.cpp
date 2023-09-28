#include <bits/stdc++.h>
using namespace std;

int DecimalToBinaryDivisionMethod(int n){
    int binaryNo = 0;
    int i = 0;
    while (n)
    {
        int bit = n % 2;
        binaryNo = bit * pow(10, i++) + binaryNo; 
        n /= 2;
    }
    return binaryNo;
}

int DecimalToBinaryBitwiseMethod(int n){
    int binaryNo = 0;
    int i = 0;
    while (n)
    {
        int bit = n & 1;
        binaryNo = bit * pow(10, i++) + binaryNo; 
        n >>= 1;
    }
    return binaryNo;
}

int main(){
    // cout << DecimalToBinaryDivisionMethod(15) << endl;
    cout << DecimalToBinaryBitwiseMethod(100) << endl;
    return 0;
}