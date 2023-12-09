#include <bits/stdc++.h>
using namespace std;

// tc: O(n) & sc: O(n)
vector<double> getCollisionTimes(vector<vector<int>> &cars)
{
    vector<double> ans(cars.size(), -1);
    stack<int> st;
    for(int i = cars.size() - 1; i>=0; i--){
        // check if car ahead of current car is faster or not, if yes then pop it as it'll never collide with current car
        while (!st.empty() && cars[i][1] <= cars[st.top()][1]) // cars[i][1] is the speed of current car and cars[st.top()][1] is the speed of the car ahead of current car
        {
            st.pop(); // pop the car ahead of current car as it'll never collide with current car
        }         
        
        while(!st.empty()){  // check if the car ahead of current car has collided with any car or not
            // if the car ahead of current car is slower than current car then it'll collide with current car 
            double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (double)(cars[i][1] - cars[st.top()][1]);
            // if the car ahead of current car has not collided with any car or it has collided with a car which is ahead of current car then it'll collide with current car
            if(ans[st.top()] == -1 || colTime <= ans[st.top()]){ 
                ans[i] = colTime; // update the collision time of current car
                break; // break the loop as current car will collide with this car only
            }
            st.pop(); // if the car ahead of current car has collided with a car which is behind current car then pop it as it'll never collide with current car
        }
        st.push(i); // push the current car in stack
    }
    return ans; // return the collision time of each car
}

int main()
{
    vector<vector<int>> cars = {{1, 2}, {2, 1}, {4, 3}, {7, 2}};
    cout << "Collision times of each car: ";
    vector<double> ans = getCollisionTimes(cars);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}