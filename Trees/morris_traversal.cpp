/* Morris traversal */

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node * left;
        Node * right;

        Node(int d){
            this->data  = d;
            this->left  = NULL;
            this->right = NULL;
        }
};

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        
        Node * crr = root;

    while(crr != NULL){

        if(crr->left == NULL){
            ans.push_back(crr->data);
            crr = crr->right;
        }
        else{
            Node * pre = crr->left;
            while(pre->right != NULL && pre->right != crr){
                pre = pre->right;
            }
            
            if(pre->right == NULL){
                pre->right = crr;
                crr = crr->left;
            }
            else{
                pre->right = NULL;
                ans.push_back(crr->data);
                crr = crr->right;
            }
        }
    }
        
        return ans;
    }
};

int main(){

    return 0;
}
