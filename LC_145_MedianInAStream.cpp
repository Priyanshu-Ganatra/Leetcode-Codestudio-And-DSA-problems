#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    priority_queue<int, vector<int>, greater<int>> mini;
    priority_queue<int> maxi;
    double median;

public:
    MedianFinder()
    {
        median = 0;
    }

    void addNum(int num)
    {
        if (maxi.size() == mini.size())
        {
            if (num > median)
            {
                mini.push(num);
                median = mini.top();
            }
            else
            {
                maxi.push(num);
                median = maxi.top();
            }
        }
        else if (maxi.size() == mini.size() + 1)
        {
            if (num > median)
            {
                mini.push(num);
            }
            else
            {
                int maxTop = maxi.top();
                maxi.pop();
                mini.push(maxTop);
                maxi.push(num);
            }
            median = (maxi.top() + mini.top()) / 2.0;
        }
        else if (maxi.size() + 1 == mini.size())
        {
            if (num > median)
            {
                int minTop = mini.top();
                mini.pop();
                maxi.push(minTop);
                mini.push(num);
            }
            else
            {
                maxi.push(num);
            }
            median = (maxi.top() + mini.top()) / 2.0;
        }
    }

    double findMedian()
    {
        return median;
    }
};

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    cout << obj->findMedian() << endl;
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    obj->addNum(4);
    cout << obj->findMedian() << endl;
    obj->addNum(5);
    cout << obj->findMedian() << endl;
    obj->addNum(6);
    cout << obj->findMedian() << endl;
    obj->addNum(7);
    cout << obj->findMedian() << endl;
    obj->addNum(8);
    cout << obj->findMedian() << endl;
    obj->addNum(9);
    cout << obj->findMedian() << endl;
    obj->addNum(10);
    cout << obj->findMedian() << endl;
    return 0;
}