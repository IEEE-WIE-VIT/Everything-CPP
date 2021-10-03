#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* head;
    Node* next;
};

Node* divide(int N, Node* head){
    Node* even=NULL;
    Node* odd=NULL;
    Node* o=NULL;
    Node* e=NULL;
    
    while(head){
        if(head->data%2==0){
            if(even =NULL){
                even=head;
                e=head;
            }
            else{
                e->next=head;
                e=e->next;
            }

        }
        else{
            if(odd=NULL){
                odd=head;
                o=head;
            }
            else{
                o->next=head;
                o=o->next;
            }
        }
        head=head->next;
    }
    if(e) e->next=odd;
    if(o) o->next=even;
    if(even) return even;
    return odd;

}

Node* createNode(int data){
    Node* head = new Node(data);
}

int main(){
createNode(1);
createNode(3);
divide(head);
}