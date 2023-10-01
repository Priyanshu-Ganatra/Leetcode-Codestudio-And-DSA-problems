#include <bits/stdc++.h>
using namespace std;

// tc: O(n*log(n)) | sc: O(m), where m = size of order string
class Solution
{
public:
    static string str;
    // custom comparator
    static bool compare(char ch1, char ch2)
    {
        // true when position of ch1 in str < position of ch2 in given order string
        return (str.find(ch1) < str.find(ch2));
        // when true is returned, ch1 will be placed before ch2 in the o/p string else it'll be placed after ch2
    }

    string customSortString(string order, string s)
    {
        str = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};

string Solution::str;

int main()
{
    Solution solution;
    string order = "cba";
    string s = "abcd";

    string sortedString = solution.customSortString(order, s);

    cout << "Original String: " << s << endl;
    cout << "Sorted String: " << sortedString << endl;

    return 0;
}
