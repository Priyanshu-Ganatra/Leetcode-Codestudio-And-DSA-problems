#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> v, int size, int index)
{
    // base case
    if (index == size)
    {
        return true;
    }
    // processing
    if (v[index] >= v[index - 1])
    {
        return isSorted(v, size, index + 1);
    }
    else{
        return false;
    }
}

int main()
{
    vector<int> v = {1};
    int size = v.size();
    int index = 1;
    cout << "Is the array sorted?" << endl;
    cout << isSorted(v, size, index);
    return 0;
}
