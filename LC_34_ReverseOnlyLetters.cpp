#include <bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string s)
{
    int low = 0, high = s.size() - 1;
    while (low < high)
    {
        if (!isalpha(s[low]))
        {
            low++;
        }
        else if (!isalpha(s[high]))
        {
            high--;
        }
        else
        {
            swap(s[low++], s[high--]);
        }
    }
    return s;
}

int main()
{
    string s = "ab-cd";
    cout << reverseOnlyLetters(s) << endl;
    return 0;
}
