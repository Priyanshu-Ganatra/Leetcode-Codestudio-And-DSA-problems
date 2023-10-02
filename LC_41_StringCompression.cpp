#include <bits/stdc++.h>
using namespace std;

// run length encoding - tc: O(n) & sc: O(1)
int compress(vector<char> &chars)
{
    int index = 0, count = 1;
    int prev = chars[0];

    for (int i = 1; i < chars.size(); i++)
    {
        if (chars[i] == prev)
        {
            count++;
        }
        else
        {
            chars[index++] = prev;
            if (count > 1)
            {
                int start = index;
                while (count)
                {
                    chars[index++] = count % 10 + '0';
                    count /= 10;
                }
                reverse(chars.begin() + start, chars.begin() + index);
            }
            prev = chars[i];
            count = 1;
        }
    }
    chars[index++] = prev;
    if (count > 1)
    {
        int start = index;
        while (count)
        {
            chars[index++] = count % 10 + '0';
            count /= 10;
        }
        reverse(chars.begin() + start, chars.begin() + index);
    }
    return index;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << compress(chars) << endl;
    return 0;
}