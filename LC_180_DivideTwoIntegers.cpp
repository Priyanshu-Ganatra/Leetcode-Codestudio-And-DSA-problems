#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long s = 0;
        long long e = abs(dividend);
        long long ans = 0;

        while(s<=e){
            long long mid = s + (e-s)/2;
            if(abs(mid*divisor)==abs(dividend)){
                return (negative)?-mid:mid;
            }
            else if (abs(mid * abs(divisor)) < abs(dividend))
            {
                // right and update ans as we need to find floor value
                ans = mid;
                s = mid + 1;
            }
            else
            {
                // left
                e = mid - 1;
            }
        }
        return (negative)?-ans:ans;
    }
};

int main() {
    Solution sol;
    cout << sol.divide(10, 3) << endl;
    cout << sol.divide(7, -3) << endl;
    cout << sol.divide(0, 1) << endl;
    cout << sol.divide(1, 1) << endl;
    cout << sol.divide(1, 2) << endl;
    cout << sol.divide(1, -1) << endl;
    cout << sol.divide(-1, 1) << endl;
    cout << sol.divide(-1, -1) << endl;
    cout << sol.divide(-1, -2) << endl;
    cout << sol.divide(-2147483648, -1) << endl;
    return 0;
}