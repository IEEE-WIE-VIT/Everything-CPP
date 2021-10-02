#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* head;
    Node* next;
};


Node* reverse( Node* head){
Node* next;
Node* prev=NULL;
Node* curr=head;

while(curr){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
return prev;
}

Node* Add2LL(Node* first,Node* second){
    first=reverse(first);
    second=reverse(second);
    Node* temp;
    Node* curr=NULL;
    Node* res=NULL;
    int c=0;
    int s=0;

    while(first!=NULL || second!=NULL){
        s=c+(first?first->data:0)+(second?second->data:0);
        c=(s>=10)?1:0;
        s=s%10;
        temp=new Node(s);
        if(res==NULL){
            res=temp;
        }
        else
        curr->next=temp;
        curr=temp;

        if(first){
            first=first->next;
        }
        if(second){
            second=second->next;
        }

        if(c>0){
            temp = new Node(c);
            curr->next=temp;
            curr=temp;
            }
    }
    
    res=reverse(curr);
}

Node* createNode(int data){
    Node* head = new Node(data);
}

int main(){
createNode(1);
createNode(3);
Add2LL(first,second);
}