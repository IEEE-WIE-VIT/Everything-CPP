#include<iostream>
using namespace std;

struct Node{
    struct Node* left;
    int val;
    struct Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

void preOrderTraversal(struct Node* r1){
    
    if(r1==NULL){
        cout<<"";
    }
    else{
        cout<<r1->val<<" ";
        preOrderTraversal(r1->left);
        preOrderTraversal(r1->right);
    }
}

void postOrderTraversal(struct Node* r1){
    if(r1==NULL){
        cout<<"";
    }
    else{
        postOrderTraversal(r1->left);
        postOrderTraversal(r1->right);
        cout<<r1->val<<" ";
    }
}

void inOrderTraversal(struct Node* r1){
    if(r1==NULL){
        cout<<"";
    }
    else{
        inOrderTraversal(r1->left);
        cout<<r1->val<<" ";
        inOrderTraversal(r1->right);
    }
}

int main(){
    struct Node *root=new Node(22);
    root->left=new Node(33);
    root->right=new Node(44);
    root->left->right=new Node(55);
    cout<<"Pre Order Traversal: ";
    preOrderTraversal(root);
    cout<<"\nIn Order Traversal: ";
    inOrderTraversal(root);
    cout<<"\nPost Order Traversal: ";
    postOrderTraversal(root);
    return 0;
}
