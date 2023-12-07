#include <bits/stdc++.h>
using namespace std;

// push and pop take O(n) time and O(1) space
class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    void printStack()
    {
        cout << endl;
        cout << "Top 1: " << top1 << endl;
        cout << "Top 2: " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << endl
                 << "Stack overflow,"
                 << " can't insert " << data << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << endl
                 << "Stack overflow,"
                 << " can't insert " << data << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << endl
                 << "Stack underflow!!!" << endl;
        }
        else
        {
            arr[top1] = 0;
            top1--;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << endl
                 << "Stack underflow!!!" << endl;
        }
        else
        {
            arr[top2] = 0;
            top2++;
        }
    }
};

int main()
{
    Stack st(6);
    st.printStack();

    st.push1(10);
    st.printStack();

    st.push1(20);
    st.printStack();

    st.push1(30);
    st.printStack();

    st.push2(100);
    st.printStack();

    st.push2(200);
    st.printStack();

    st.push2(300);
    st.printStack();

    st.push1(40);
    return 0;
}
