#include <bits/stdc++.h>
using namespace std;

// tc: O(n*n!) and sc: O(n)
void printPermutations(string &str, int i)
{
    // base case
    if (i >= str.size())
    {
        cout << str << " ";
        return;
    }

    for (int j = i; j < str.size(); j++)
    {
        swap(str[i], str[j]);
        // recursive call
        printPermutations(str, i + 1);
        // backtrack - means undo the changes done in the current call
        swap(str[i], str[j]);
    }
}

int main()
{
    string str = "abc";
    printPermutations(str, 0);
    return 0;
}