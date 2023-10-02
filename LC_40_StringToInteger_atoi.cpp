#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int num = 0, i = 0, sign = 1;
    while(s[i] == ' ') i++;
    if(i < s.size() && s[i] == '+' || s[i] == '-'){
        sign = (s[i] == '+') ? 1 : -1;
        i++;
    }

    while(i < s.size() && isdigit(s[i])){
        if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7')){
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        num = num*10 + (s[i] - '0');
        i++;
    }
    return num*sign;
}   

int main()
{
    string s = "42";
    cout << myAtoi(s) << endl;
    return 0;
}