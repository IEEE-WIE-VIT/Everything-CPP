
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
 
/* Function to implement Preorder Traversal */
void preorder(Node *root)
{
    /* Check Base Condition */
    if(root == NULL)
    return;
    
    /* Create an Empty Stack */
    stack <Node *> st;
    
    /* Push root Node into it */
    st.push(root);
    
    while(!st.empty())
    {
        /* Pop and print top node */
        Node *temp = st.top();
        st.pop();
        cout<<temp -> data<<" ";
        
        /* Push Right Child, if exists */
        if(temp -> right)
        st.push(temp -> right);
        
        /* Push Left Child, if exists */
        if(temp -> left)
        st.push(temp -> left);
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
    
    /* Calling function to perform preorder traversal*/
    cout<<"The Preorder Traversal of the Given Binary Tree is: ";
    preorder(root);
}