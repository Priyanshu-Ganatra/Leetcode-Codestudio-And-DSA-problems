#include <bits/stdc++.h>
using namespace std;

static bool myComp(string a, string b)
{
    return a + b > b + a;
}

string largestNumber(vector<int> &nums)
{
    vector<string> strNums;
    for (int num : nums)
        strNums.push_back(to_string(num));

    sort(strNums.begin(), strNums.end(), myComp);
    if (strNums[0] == "0") return "0";    
    string res = "";
    for (string str : strNums)
        res += str;
    return res;    
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    return 0;
}