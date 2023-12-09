#include <bits/stdc++.h>
using namespace std;

class Car
{
public:
    int speed, pos;
    Car(int p, int s) : pos(p), speed(s){};
};

static bool carsSorter(Car &a, Car &b)
{
    return a.pos < b.pos;
}

// tc: O(nlogn) and sc: O(n)
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<Car> cars; // stores the cars in sorted order of their position
    int size = position.size(); // size of the position and speed vectors
    for (int i = 0; i < size; i++) // populating the cars vector
    {
        cars.push_back(Car(position[i], speed[i])); // creating a car object and pushing it into the cars vector
    } 
    sort(cars.begin(), cars.end(), carsSorter); // sorting the cars vector in ascending order of each car's position

    stack<float> st; // float because we need to store time which can be in decimals
    for(auto car : cars)
    {
        float time = (target - car.pos) / (float)car.speed; // time = distance / speed
        // if time is greater than the top of stack, then it means that the car will reach the destination before the car at the top of stack
        while (!st.empty() && time >= st.top()) // st.top() is the time taken by the previous car to reach the destination
        {
            // if the previous car will reach the destination before the current car, then at a point of time, the current car will be blocked by the previous car and that makes it a new fleet
            st.pop();
        }
        // push the current car's time to reach the destination on the stack
        st.push(time); 
    }
    return st.size(); // this will give the number of car fleets that'll reach the destination at the same time
}

int main()
{
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    cout << "Number of car fleets that'll reach the destination at the same time: " << endl;
    cout << carFleet(target, position, speed) << endl;
    return 0;
}