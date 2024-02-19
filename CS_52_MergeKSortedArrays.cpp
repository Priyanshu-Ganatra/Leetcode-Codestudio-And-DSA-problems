#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O((N * K) * log(K))
    Space Complexity: O(N * K)

    Where N is the total number of elements in all the arrays, and K is the
   number of arrays.
*/

#include <queue>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> result;
    // Create a min heap to store atmost k heap nodes at a time.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
    minHeap;

    for (int i = 0; i < kArrays.size(); i++)
    {
        minHeap.push({kArrays[i][0], {i, 0}});
    }

    while (minHeap.empty() == false)
    {

        // Remove the minimum element from the heap.
        pair<int, pair<int, int>> curr = minHeap.top();
        minHeap.pop();

        // i is the array number and j is the index of the removed element in the
        // ith array.
        int i = curr.second.first;
        int j = curr.second.second;

        // Add the removed element to the output array.
        result.push_back(curr.first);

        // If the next element of the extracted element exists, add it to the heap.
        if (j + 1 < kArrays[i].size())
        {
            minHeap.push({kArrays[i][j + 1], {i, j + 1}});
        }
    }

    // Return the output array.
    return result;
}

int main()
{
    vector<vector<int>> kArrays = {{2, 6, 12, 34}, {1, 9, 20, 1000}, {23, 34, 90, 2000}};

    vector<int> result = mergeKSortedArrays(kArrays, kArrays.size());

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}