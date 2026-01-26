class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &x:flights){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,int>> q;
        q.push({src,0}); // {node,distance}
        int steps=0;
        while(!q.empty() && steps<=k){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int node=q.front().first;
                int d=q.front().second;
                q.pop();
                for(auto &y:adj[node]){
                    int v=y.first;
                    int ew=y.second;
                    if(dist[v]>d+ew){
                        dist[v]=d+ew;
                        q.push({v,dist[v]});
                    }
                }
            }
            steps++;

        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
        
    }
};