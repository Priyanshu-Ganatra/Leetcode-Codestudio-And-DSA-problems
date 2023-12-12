#include <bits/stdc++.h>
using namespace std;

// tc : O(n) sc : O(1)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0; // deficit is the amount of gas we need to reach the next station
    int balance = 0; // balance is the amount of gas we have in our tank which is calculated by subtracting the cost from the gas
    // index of the starting point
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        int temp = balance + gas[i] - cost[i]; // balance after reaching the next station from the current station, if negative we can't reach the next station
        if (temp < 0)
        {
            // if balance is negative, we can't start from this station
            // as we will run out of gas before reaching the next station
            // so we start from the next station
            start = i + 1;
            // deficit is the amount of gas we need to reach the next station
            deficit += abs(temp);
            // reset balance
            balance = 0;
        }
        else
        {   
            balance = temp;
        }
    }
    // if the total balance is less than the total deficit, we can't complete the circuit
    // else we can start from the start index
    return (balance - deficit >= 0) ? start : -1;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}