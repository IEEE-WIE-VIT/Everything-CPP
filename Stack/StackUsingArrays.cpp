#include <iostream>
using namespace std;

#define n 100  // Stack's Capacity

class Stack
{

    int *arr;
    int top;

public:
    Stack()
    {

        arr = new int[n];
        top = -1;
    }

    void push(int dataValue)
    {

        if (top == n - 1)
        {
            cout << "StackOverflow" << endl;
            return;
        }

        top++;
        cout<<dataValue<<" pushed to Stack"<<endl;
        arr[top] = dataValue;
    }

    void pop()
    {

        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }

        cout<<arr[top]<<" removed from Stack"<<endl;
        top--;
    }

    int peek()
    {

        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top==-1;
    }
};

int main()
{
    Stack stk;

    cout<<"------------"<<endl;

    stk.push(5);
    stk.push(12);
    stk.push(14);

    cout<<"------------"<<endl;

    cout<<"At the Stack's Peak: "<<stk.peek()<<endl;

    cout<<"------------"<<endl;

    stk.pop();
    stk.pop();

    cout<<"is Stack Empty: "<<stk.isEmpty()<<endl;

    stk.pop();
    
    cout<<"is Stack Empty: "<<stk.isEmpty()<<endl;

    cout<<"------------"<<endl;

    return 0;
}