class Solution
{
    map<int,map<int,multiset<int>>> mp;
    void solve(Node* root, int col, int row){
        if(!root) return;

        mp[col][row].insert(root->data);
        solve(root->left, col-1, row+1);
        solve(root->right, col+1, row+1);
    }
    public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        solve(root,0,0);

        vector<int> v;
        for(auto x: mp){
            for(auto y: x.second){
                for(auto z: y.second){
                    v.push_back(z);
                    break;
                }
                break;
            }
        }
        return v;
    }

};
