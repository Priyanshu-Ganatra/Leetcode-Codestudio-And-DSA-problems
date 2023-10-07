#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *ptr = (int *)malloc(sizeof(int));
    free(ptr); // Now 'ptr' is a dangling pointer
    *ptr = 10; // Accessing memory through a dangling pointer is undefined behavior
    cout  << *ptr << endl; 
    return 0;
}
