class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    vector<int> ans,depth,cost;
    int c=0;
    void dfs(int node,int parent,int dpth,int cst){
        depth[node]=dpth;
        cost[node]=cst;
        for(auto &x:adj[node]){
            int v=x.first;
            int rf=x.second; // real or fake
            if(v==parent) continue;
            if(rf==0) c++;
            int temp_cost=cst;
            if(rf==0) temp_cost++;
            dfs(v,node,dpth+1,temp_cost);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        ans.assign(n,0);
        depth.assign(n,0);
        cost.assign(n,0);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back({v,1}); // real
            adj[v].push_back({u,0}); // fake, so that i can travel to all nodes without blocks
        }

        dfs(0,-1,0,0);
        ans[0]=c;
        for(int i=1;i<n;i++){
            ans[i]=(depth[i]-cost[i])+c-cost[i]; // i to src + src to all - src to i (cuzz this time i have to find from i to all )
        }
        return ans;        
    }
};