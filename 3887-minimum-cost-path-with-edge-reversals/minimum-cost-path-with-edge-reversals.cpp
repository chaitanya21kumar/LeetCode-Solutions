class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);
        for(auto &x:edges){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                for(auto &y:adj[x]){
                    int v=y.first,w=y.second;
                    if(dist[v]>dist[x]+w){
                        dist[v]=dist[x]+w;
                        q.push(v);
                    }
                }
            }
        }
        int ans=dist[n-1];
        if(ans==INT_MAX) return -1;
        return ans;
         
    }
};