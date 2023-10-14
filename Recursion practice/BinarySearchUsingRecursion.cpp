#include <bits/stdc++.h>
using namespace std;

int recursiveBs(vector<int> v, int s, int e, int key)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (v[mid] == key)
    {
        return mid;
    }
    if (v[mid] < key)
    {
        return recursiveBs(v, mid + 1, e, key);
    }
    else
    {
        return recursiveBs(v, s, mid - 1, key);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int key = 5;
    int s = 0;
    int e = v.size() - 1;
    cout << "Index of " << key << " is: ";
    cout << recursiveBs(v, s, e, key);
    return 0;
}
