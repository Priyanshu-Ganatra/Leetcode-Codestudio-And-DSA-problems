#include <bits/stdc++.h>
using namespace std;

bool canDistributeHelper(vector<int> &counts, vector<int> &quantity, int iThCustomer)
{
    // base case
    if (iThCustomer == quantity.size())
        return true;

    // try to give the iTh customer the quantity from each of the counts array elements
    for (int i = 0; i < counts.size(); i++)
    {
        // if the iTh customer can be given the quantity
        if (counts[i] >= quantity[iThCustomer])
        {
            // distribute the quantity to the iTh customer
            counts[i] -= quantity[iThCustomer];
            // see if we can distribute the remaining quantities to the remaining customers
            if (canDistributeHelper(counts, quantity, iThCustomer + 1))
            {
                return true; // if yes, then return true
            }
            counts[i] += quantity[iThCustomer]; // backtrack, because we need to try other possibilities
        }
    }
    return false;
}

// tc : O(N^2 * 2^N) & sc : O(N)
bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> freq; // stores the frequency of each number in the nums array
    for (auto num : nums)         // store the frequency of each number in the nums array
    {
        freq[num]++;
    }
    vector<int> counts; // transfer the frequency of each number in the map to the counts array
    for (auto it : freq)
    {
        counts.push_back(it.second);
    }
    // Optimization
    // sort the quantity array in descending order to try to give the largest quantity to the customer first
    sort(quantity.rbegin(), quantity.rend()); // this prevents the recursion from going too deep as we try to give the largest quantity to the customer first and if it fails, we backtrack and try to give the next largest quantity to the customer and so on
    return canDistributeHelper(counts, quantity, 0);
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    vector<int> quantity = {2};
    if (canDistribute(nums, quantity))
        cout << "Yes we can distribute the integers in the array in the given quantity";
    else
        cout << "false";
    return 0;
}