#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &m)
{
    int n = m.size();
    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m[i].size(); j++)
        {
            swap(m[i][j], m[j][i]);
        }
    }

    // reverse
    for (int i = 0; i < n; i++)
    {
        reverse(m[i].begin(), m[i].end());
    }
}

int main()
{
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    cout << "The rotated matrix is: " << endl;
    rotate(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}