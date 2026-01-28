class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    typedef pair<int,int> p;
    priority_queue<p,vector<p>,greater<p>> pqg;
    void f(int src,int n,int t){
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,src}); // {dist,node}
        while(!pq.empty()){
            auto x=pq.top();
            int dst=x.first;
            int node=x.second;
            pq.pop();
            if(dst>dist[node]) continue;
            for(auto &y:adj[node]){
                int v=y.first;
                int w=y.second;
                if(dst+w<dist[v]){
                    dist[v]=dst+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(dist[i]<=t){
                c++;
            }
        }
        pqg.push({c,-src});
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        for(auto &x:edges){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        for(int i=0;i<n;i++){
            f(i,n,distanceThreshold);
        }

        return -1*pqg.top().second;




        
    }
};