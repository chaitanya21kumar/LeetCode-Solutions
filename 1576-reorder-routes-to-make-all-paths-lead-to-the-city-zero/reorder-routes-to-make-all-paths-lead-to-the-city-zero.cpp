class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int c=0;
    void dfs(int node,int parent){
        for(auto &x:adj[node]){
            int v=x.first;
            int rf=x.second; // real or fake
            if(parent==v) continue;
            if(rf==1) c++;
            dfs(v,node);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {

        for(auto x:connections){
            int u=x[0];
            int v=x[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        dfs(0,-1);
        return c;

    }
};