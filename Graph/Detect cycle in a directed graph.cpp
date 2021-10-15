class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs_vis){
        vis[node]=1;
        dfs_vis[node]=1;

        for(auto x: adj[node]){
            if(!vis[x]){
                if(checkCycle(x,adj,vis,dfs_vis))
                return true;
            }else if(dfs_vis[x]){
                return true;
            }
        }
        dfs_vis[node]=0;
        return false;
    }


    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> dfs_vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfs_vis))
                return true;
            }
        }
        return false;
    }
};
