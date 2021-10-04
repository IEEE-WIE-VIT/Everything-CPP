#include <iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* next;

    Node(int value) {
         data = value;
         next = NULL;
     }
};

class Stack {

    Node* top;

    public:

    Stack() {
         top = NULL;
    }

    void push(int dataValue) {
        Node* newNode = new Node(dataValue);
        newNode->next = top;
        top = newNode;
        cout<<dataValue<<" pushed to Stack"<<endl;
    }

    void pop() {
        if (top==NULL)
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
        cout<<top->data<<" removed from Stack"<<endl;
        Node* toDelete = top;
        top = top->next;

        delete toDelete;
    }

    int peek() {
        if (top==NULL)
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top==NULL;
    }

};


int main () {

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