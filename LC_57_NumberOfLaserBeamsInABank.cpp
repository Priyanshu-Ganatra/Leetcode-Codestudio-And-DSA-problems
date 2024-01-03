// This question seems to be a bit tricky but it is not. It is just a simple observation.
#include <bits/stdc++.h>
using namespace std;

int countDevices(string &row)
{
    int count = 0;
    for (auto ch : row)
    {
        if (ch == '1')
            count++;
    }
    return count;
}

// // tc : O(n^2) and sc : O(n)
// int numberOfBeams(vector<string> &bank)
// {
//     vector<int> devices;
//     for (auto row : bank)
//         devices.push_back(countDevices(row)); // count number of devices in each row and store it in devices vector
//     int beams = 0;
//     for(int i = 0; i < devices.size(); i++){
//         int j = i + 1; // j will point to the next row after i in devices vector
//         while(j < devices.size()){
//             // this is the main logic of this question and it is explained in the question itself
//             beams += devices[i] * devices[j];
//             if(devices[j] == 0) j++; // if devices[j] == 0, then there is no device in that row, so we can skip that row
//             else break; // if devices[j] != 0, then there is a device in that row, so we stop because we can't go further as per the question
//         }
//     }
//     return beams;
// }

// tc: O(M*N) and sc: (1)
int numberOfBeams(vector<string> &bank)
{
    // prev will store the number of devices in the previous row and ans will store the total number of beams
    int prev = 0, ans = 0;

    // we will iterate through each row and count the number of devices in that row and store it in count
    // if count != 0, then we will add prev * count to ans and update prev to count so that we can use it in the next iteration
    for (string s : bank)
    {
        int count = countDevices(s);
        if (count != 0)
        {
            ans += (prev * count);
            prev = count;
        }
    }

    return ans;
}

int main()
{
    vector<string> bank = {"1000", "1110", "1110", "0000"};
    cout << "Number of beams: ";
    cout << numberOfBeams(bank) << endl;
    return 0;
}
