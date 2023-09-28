#include <bits/stdc++.h>
using namespace std;

int BinaryToDecimal(int n){
    int decimal = 0, i = 0;
    while (n)
    {
        int bit = n % 10;
        decimal += bit * pow(2, i++); // as base of binary is 2
        n /= 10; 
    }
    return decimal;
}

int main(){
    cout << BinaryToDecimal(1111);
    return 0;
}