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
 
/* Function to Implement inorder traversal */
void inorder(Node *root)
{
    /* Check Base Condition */
    if(root == NULL)
    return;
    
    /* Create an Empty Stack */
    stack <Node *> st;
    
    Node *currNode = root;
    
    while(currNode != NULL || !st.empty())
    {
        /* Reach the left most node of the tree */
        while(currNode)
        {
            st.push(currNode);
            currNode = currNode -> left;
        }
        
        /* Assign Left to Left most node */
        currNode = st.top();
        
        /* Pop out the stack */
        st.pop();
        
        /* Print currNode data */
        cout<<currNode -> data <<" ";
        
        /* Traverse right Subtree */
        currNode = currNode -> right;
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
    
    /* Calling function to perform inorder traversal*/
    cout<<"The Inorder Traversal of the Given Binary Tree is: ";
    inorder(root);
}