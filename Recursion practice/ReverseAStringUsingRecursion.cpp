#include <bits/stdc++.h>
using namespace std;

// tc : O(n) & sc : O(n) to be precise tc: T(n/2 + 1) & sc : T(n/2 + 1)
void reverse(string &str, int s, int e){
    if(s >= e){
        return;
    }
    swap(str[s], str[e]);
    reverse(str, s + 1, e - 1);
}

int main(){
    cout << "Enter a string: ";
    string str;
    cin >> str;
    reverse(str, 0, str.length() - 1);
    cout << "Reversed string: " << str;
    return 0;
}
