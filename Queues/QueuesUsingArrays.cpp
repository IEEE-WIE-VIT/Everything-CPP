#include <iostream>
using namespace std;

#define n 5  // Queue's Capacity

class Queue {

    int* arr;
    int front;
    int back;

    public:

    Queue() {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue (int dataValue){

        if (front==-1)
        {
            front++;
        }

        if (back==n-1)
        {
            cout<<"QueueOverflow"<<endl;
            return;
        }
        
        
        back++;
        cout<<dataValue<<" added to Queue"<<endl;
        arr[back] = dataValue;
    }

    void dequeue () {
        if (front==-1 || front>back)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        
        cout<<arr[front]<<" removed from Queue"<<endl;
        front++;

    }

    int peek() {
        if (front==-1 || front>back)
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }

        return arr[front];
        
    }

    bool isFull() {

        if (back-front == n-1)
        {
            return true;
        }
        
        return false;
    }

    bool isEmpty() {
        if (front==-1 || front>back)
        {
            return true;
        }
        return false;
        
    }

};

int main() {

    Queue q;

    cout<<"------------"<<endl;

    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(12);

    cout<<"------------"<<endl;

    cout<<"is Queue Full: "<<q.isFull()<<endl;

    cout<<"------------"<<endl;

    q.enqueue(14);
    q.enqueue(72);

    cout<<"------------"<<endl;

    cout<<"is Queue Full: "<<q.isFull()<<endl;

    cout<<"------------"<<endl;

    q.dequeue();
    q.dequeue();

    cout<<"------------"<<endl;

    cout<<"At the Queue's Peak: "<<q.peek()<<endl;

    cout<<"------------"<<endl;
    q.dequeue();
    q.dequeue();

    cout<<"------------"<<endl;

    cout<<"is Queue Empty: "<<q.isEmpty()<<endl;

    cout<<"------------"<<endl;

    q.dequeue();

    cout<<"------------"<<endl;

    cout<<"is Queue Empty: "<<q.isEmpty()<<endl;

    cout<<"------------"<<endl;

    return 0;
}