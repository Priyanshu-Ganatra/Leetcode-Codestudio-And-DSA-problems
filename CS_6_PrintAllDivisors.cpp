#include <bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n) {
    // Write your code here
    vector<int> list;
    for(int i = 1; i <= sqrt(n); i++){
        if(n%i==0){
            list.push_back(i);
            if((n/i) != i){ // Making sure that n/i is not repeated
                list.push_back(n/i); // pushing the 2nd divisor which when multiplied with the 1st divisor gives n
            }
        }
    }
    sort(list.begin(), list.end());
    return list;
}

int main(){
    int n = 36;
    vector<int> list = printDivisors(n);
    for(auto &it: list){
        cout << it << ' ';
    }
    return 0;
}