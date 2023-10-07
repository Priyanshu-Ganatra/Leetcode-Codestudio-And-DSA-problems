#include <bits/stdc++.h>
using namespace std;

int main(){
    char str[10] = "abcd";
    char *cptr = str; // same as char *cptr = &str[0], this works as str is char* type
    cout << cptr << endl;
    // char (*ch)[10] = &str; // char* ch = &str will give error as &str is char(*)[10] type
    // cout << *ch << endl;
    return 0;
}
