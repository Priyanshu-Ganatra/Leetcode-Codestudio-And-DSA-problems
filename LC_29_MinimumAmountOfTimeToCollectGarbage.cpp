#include <bits/stdc++.h>
using namespace std;

int garbageCollection(vector<string> &garbage, vector<int> &travel)
{
    int pickP = 0;
    int pickG = 0;
    int pickM = 0;

    int travelP = 0;
    int travelG = 0;
    int travelM = 0;

    int lastP = 0;
    int lastG = 0;
    int lastM = 0;

    // calc pick time & find out the index where each type of garbage last occurs
    for (int i = 0; i < garbage.size(); i++)
    {
        string curr = garbage[i];
        for (char ch : curr)
        {
            if (ch == 'P')
            {
                pickP++;
                lastP = i;
            }
            else if (ch == 'G')
            {
                pickG++;
                lastG = i;
            }
            else
            {
                pickM++;
                lastM = i;
            }
        }
    }

    // calc travel time
    for (int i = 0; i < lastP; i++)
    {
        travelP += travel[i];
    }
    for (int i = 0; i < lastG; i++)
    {
        travelG += travel[i];
    }
    for (int i = 0; i < lastM; i++)
    {
        travelM += travel[i];
    }
    int ans = pickP + travelP + pickG + travelG + pickM + travelM;
    return ans;
}


int main()
{
    vector<string> garbage = {"G","P","GP","GG"};
    vector<int> travel = {2, 4, 3};
    cout << "Minimum amount of time to collect garbage: " << garbageCollection(garbage, travel) << endl;
    return 0;
}