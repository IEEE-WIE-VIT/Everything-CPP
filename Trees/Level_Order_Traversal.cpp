class Solution
{
    public:
    //Function to find the level order traversal of Binary Tree.
    
        vector<int> levelOrder(Node *root) {

            vector<int> ans;
            Node* curr;
            int count;
            if(root == NULL)
            return ans;
            queue<Node*> q;
            q.push(root);
            while(q.empty()==false)
            {
                count = q.size();
                for(int i=0; i<count; i++)
                {
                    curr = q.front();
                    q.pop();
                    ans.push_back(curr->data);

                    if(curr->left!=NULL)
                    q.push(curr->left);

                    if(curr->right!=NULL)
                    q.push(curr->right);
                }
            }
            return ans;
    }
};