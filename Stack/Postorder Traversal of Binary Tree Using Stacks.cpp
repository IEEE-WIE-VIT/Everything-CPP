#include<iostream>
using namespace std;
 
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int ele)
    {
        data = ele;
        left = NULL;
        right = NULL;
    }
} Node;
 
/* Function to implement Postorder Traversal */
void postorder(Node *root)
{
    /* Check Base Condition */
    if(root == NULL)
    return;
    
    /* Create an Empty Stack */
    stack <Node *> st1, st2;
    
    /* Push root Node into first stack */
    st1.push(root);
    
    while(!st1.empty())
    {
        /* Pop top node */
        Node *temp = st1.top();
        st1.pop();
        
        /* Push Popped Node into second stack */
        st2.push(temp);
        
        /* Push Left Child, if exists */
        if(temp -> left)
        st1.push(temp -> left);
        
        /* Push Right Child, if exists */
        if(temp -> right)
        st1.push(temp -> right);
        
    }
    
    /* Print Elements of second stack; which are stored in reverse postorder traversal */
    while(!st2.empty())
    {
        Node *temp = st2.top();
        cout<<temp -> data<<" ";
        st2.pop();
    }
    
}
 
int main()
{
    /* Creating a Binary tree and inserting some nodes in it */
    Node *root = NULL;
    
    root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node (7);
    root -> left -> right -> left = new Node(8);
    root -> right -> left -> right = new Node(9);
    
    /* Calling function to perform postorder traversal*/
    cout<<"The Postorder Traversal of the Given Binary Tree is: ";
    postorder(root);
}