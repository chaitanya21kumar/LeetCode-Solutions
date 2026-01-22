class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> vis;
    typedef long long int ll;
    void dfs(ll i,ll &s){
        vis[i]=1;
        s++;
        for(auto &x:adj[i]){
            if(!vis[x]) dfs(x,s);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        vis.assign(n+1,0);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll cur_rem=n;
        ll ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ll s=0;
                dfs(i,s);
                ans+=(s*(cur_rem-s));
                cur_rem-=s;
            }
        }
        return ans;
    }
};