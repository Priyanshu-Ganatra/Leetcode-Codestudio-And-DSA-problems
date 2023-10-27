#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> mp = {{{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}}};

// tc : O(log₁₀n) & sc : O(log₁₀n) as the number of digits in the number is log₁₀n where n is the number itself
string numberToWords(int num)
{
    // base cases
    if (num == 0)
        return "Zero";

    for (auto it : mp)
    {
        if (num >= it.first)
        {
            string a = "";
            if (num >= 100) // to calculate the amount of hundreds, thousands, millions, or billions etc. the number should be >= 100, ex: 123, 2347, 33453, 923456, 1234567, 92345678, 523456789
            {
                a = numberToWords(num / it.first) + " "; // it.first is the number, ex: 100, 1000, 1000000, 1000000000 which is used to divide the number to get the amount of hundreds, thousands, millions, or billions etc.
            }
            string b = it.second;
            string c = "";
            // remaining number after dividing by it.first, ex: 123 % 100 = 23, 2347 % 1000 = 347
            if (num % it.first != 0) // != 0 because if the number is 100, 1000, 1000000, 1000000000 then we don't need to calculate the remaining number, ex: 100 % 100 = 0, 1000 % 1000 = 0, 1000000 % 1000000 = 0, 1000000000 % 1000000000 = 0
            {
                c =  " " + numberToWords(num % it.first); 
            }
            return a + b + c;
        }
    }
    return "";
}

int main()
{
    int num = 123;
    cout << "Number: " << num << endl;
    cout << "Number in words: " << numberToWords(num) << endl;
    return 0;
}