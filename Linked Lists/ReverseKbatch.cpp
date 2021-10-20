#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* head;
    Node* next;
};

int c;
Node* reverse( Node* head, int k){
Node* next;
Node* prev=NULL;
Node* curr=head;

while(curr!=NULL && c<k){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    c++
}
if(next!=NULL){
    head->next=reverse(next,k);
}
return prev;
}

Node* createNode(int data){
    Node* head = new Node(data);
}

int main(){
    int k;
    cin>>k;
createNode(1);
createNode(3);
reverse(head,3);
}