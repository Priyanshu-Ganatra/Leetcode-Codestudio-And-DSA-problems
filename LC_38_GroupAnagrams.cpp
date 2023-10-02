#include <bits/stdc++.h>
using namespace std;

std::array<int, 256> createHash(string s)
{
    std::array<int, 256> hash = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // tc: O(n*klogk) & sc: O(n*k), where n = strs.size() & k = length of largest string
    // map<string, vector<string>> mp;
    // for(auto str: strs){
    //     string temp = str;
    //     sort(temp.begin(), temp.end());
    //     mp[temp].push_back(str);
    // }
    // vector<vector<string>> res;
    // for(auto it: mp){
    //     res.push_back(it.second);
    // }
    // return res;

    // tc: O(n*k) & sc: O(n*k), where n = strs.size() & k = length of largest string
    map<std::array<int, 256>, vector<string>> mp;
    for (auto str : strs)
    {
        mp[createHash(str)].push_back(str);
    }
    vector<vector<string>> res;
    for (auto it : mp)
    {
        res.push_back(it.second);
    }
    return res;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (auto v : res)
    {
        for (auto s : v)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}
