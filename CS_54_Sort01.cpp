#include <bits/stdc++.h>
using namespace std;

void sortZeroesAndOne(int input[], int size)
{
    int i = 0;
    int l = size - 1;
    while (i < l)
    {
        if (input[i] == 0)
        {
            i++;
        }
        else
        {
            swap(input[i], input[l]);
            l--;
        }
    }
}

int main()
{
    int input[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    int size = sizeof(input) / sizeof(input[0]);
    sortZeroesAndOne(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}