class Solution {
public:
    typedef long long int ll;
    void dfs(int i,int n,int &cs,vector<int> &vis){

        vis[i]=1;
        cs++;
        for(auto &x:adj[i]){
            if(!vis[x]) dfs(x,n,cs,vis);
        }

    }
    unordered_map<int,vector<int>> adj;
    long long countPairs(int n, vector<vector<int>>& edges) {
        adj.clear();
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll ans=0;
        int tc=n;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            int cs=0;
            if(!vis[i]){
                dfs(i,n,cs,vis);
            }
            ans+=((ll)cs*(tc-cs));
            tc-=cs;
        }
        return ans;

        
    }
};