#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    vector<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            pair<int, int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            int oldMin = st.back().second;
            p.second = min(oldMin, val);
            st.push_back(p);
        }
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        pair<int, int> rightmostPair = st.back();
        return rightmostPair.first;
    }

    int getMin()
    {
        pair<int, int> rightmostPair = st.back();
        return rightmostPair.second;
    }
};

int main()
{
    MinStack *obj = new MinStack();
    obj->push(-3);
    obj->push(5);
    obj->push(4);
    obj->push(3);
    obj->push(2);
    obj->push(1);
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    cout << obj->getMin() << endl;
    return 0;
}