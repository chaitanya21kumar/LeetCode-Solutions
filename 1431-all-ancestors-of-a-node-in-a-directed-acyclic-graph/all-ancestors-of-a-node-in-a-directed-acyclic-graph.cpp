class Solution {
public:
    void dfs(int s,int cn,vector<vector<int>> &adj,unordered_map<int,vector<int>> &m,vector<int> &vis){
        vis[cn]=1;
        if(cn!=s){
            m[cn].push_back(s);
        }
        for(auto &x:adj[cn]){
            if(!vis[x]){
                dfs(s,x,adj,m,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(auto &x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
        }
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            vector<int> vis(n);
            dfs(i,i,adj,m,vis); // {source,curr_node,adj,m,vis}
        }
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            v[i]=m[i];
        }
        return v;
        
    }
};