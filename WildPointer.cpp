#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *ptr;  // 'ptr' is a wild pointer because it is uninitialized
    *ptr = 10; // Accessing memory through a wild pointer is undefined behavior
    cout << *ptr << endl; // doesn't print anything as the memory is not allocated
    return 0;
}
