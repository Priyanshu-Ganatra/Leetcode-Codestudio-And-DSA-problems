#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st; 
    StockSpanner()
    {
    }

    // tc : O(n) and sc: O(n)
    int next(int price)
    {
        int currentStockSpan = 1; // span of current day is 1
        // if the price of current day is greater than or equal to the price of the day on top of stack (previous day) then add the previous
        // day's span count and discard the previous day from stack, we do this until we find a day whose price is greater than the price of current day
        while(!st.empty() && st.top().first <= price){ 
            currentStockSpan += st.top().second; // add the previous day's span count to current day's span count
            st.pop(); // discard the previous day from stack
        }
        st.push({price, currentStockSpan}); // push the current day in stack
        return currentStockSpan; // return the span of current day
    }
};

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    cout << "Stock spanner: ";
    StockSpanner *obj = new StockSpanner();
    for (auto x : prices)
    {
        cout << obj->next(x) << " ";
    }
    cout << endl;
    return 0;
}