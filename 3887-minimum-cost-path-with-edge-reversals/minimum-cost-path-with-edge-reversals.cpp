class Solution {
public:
    typedef pair<int,int> p;
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);
        for(auto &x:edges){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int node=x.second;
            int d=x.first;
            if(d>dist[node]) continue;
            if(node==n-1) return dist[node];
            for(auto &y:adj[node]){
                int v=y.first,w=y.second;
                if(dist[v]>dist[node]+w){
                    dist[v]=dist[node]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return -1;
        
        
    }
};