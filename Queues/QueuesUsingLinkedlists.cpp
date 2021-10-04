#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int dataValue) {
        data = dataValue;
        next = NULL;
    }
};

class Queue {

    Node* front;
    Node* back;

    public:
    Queue() {
        front = NULL;
        back = NULL;
    }

    void enqueue(int dataValue){
        Node* newNode = new Node(dataValue);
        if (front==NULL)
        {
            front = newNode;
            back = newNode;
            cout<<dataValue<<" added to Queue"<<endl;
            return;
        }
        
        back->next = newNode;
        back = newNode;
        cout<<dataValue<<" added to Queue"<<endl;
    }

    void dequeue() {
        if (front==NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        Node* toDelete = front;
        cout<<front->data<<" removed from Queue"<<endl;
        front = front->next;
        delete toDelete;
    }

    int peek() {
        if (front==NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        if (front==NULL)
        {
            return true;
        }
        return false;
    }

    bool isFull() {
        // ~~~~~ Query ~~~~~
        return false;
    }
};

int main() {

    Queue q;

    cout<<"------------"<<endl;

    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(12);

    // cout<<"------------"<<endl;

    // cout<<"is Queue Full: "<<q.isFull()<<endl;

    // cout<<"------------"<<endl;

    q.enqueue(14);
    q.enqueue(72);

    // cout<<"------------"<<endl;

    // cout<<"is Queue Full: "<<q.isFull()<<endl;

    // cout<<"------------"<<endl;

    q.dequeue();
    q.dequeue();

    cout<<"------------"<<endl;

    cout<<"At the Queue's Peak: "<<q.peek()<<endl;

    cout<<"------------"<<endl;
    q.dequeue();
    q.dequeue();

    // cout<<"------------"<<endl;

    // cout<<"is Queue Empty: "<<q.isEmpty()<<endl;

    // cout<<"------------"<<endl;

    q.dequeue();

    cout<<"------------"<<endl;

    cout<<"is Queue Empty: "<<q.isEmpty()<<endl;

    cout<<"------------"<<endl;

    return 0;
}