#include <bits/stdc++.h>
using namespace std;

int getTime(string &time)
{
    int hours = stoi(time.substr(0, 2));
    int mins = stoi(time.substr(3));
    int timeInMins = (hours * 60) + mins;
    return timeInMins;
}

int findMinDifference(vector<string> &timePoints)
{
    vector<bool> timeSeen(1440, false);
    for (auto &timepoint : timePoints)
    {
        int timeInMins = getTime(timepoint);

        // If current time is already seen, return 0.
        if (timeSeen[timeInMins])
            return 0;
        timeSeen[timeInMins] = true;
    }

    // Find minimum time difference
    int minTimeDiff = INT_MAX, firstTime = INT_MIN, prevTime = -1;

    for (int i = 0; i < 1440; i++)
    {
        if (timeSeen[i])
        {
            if (firstTime == INT_MIN)
            {
                firstTime = i;
                prevTime = i;
            }
            else
            {
                minTimeDiff = min({minTimeDiff, i - prevTime, 1440 - i + prevTime}); // 1440 - i + prevTime is for the case when i is less than prevTime and we need to consider the circular nature of the clock.
                prevTime = i; // Update prevTime
            }
        }
    }
    return min({minTimeDiff, prevTime - firstTime, 1440 - prevTime + firstTime}); // 1440 - prevTime + firstTime is for the case when prevTime is less than firstTime and we need to consider the circular nature of the clock.
}

int main()
{
    vector<string> timePoints = {"23:59", "00:00"};
    cout << findMinDifference(timePoints) << endl;
    return 0;
}
