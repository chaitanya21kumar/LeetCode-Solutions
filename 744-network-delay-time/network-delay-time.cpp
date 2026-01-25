class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        typedef pair<int,int> p;
        for(auto &x:times){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto &x:adj[node]){
                int v=x.first;
                int ew=x.second;
                if(d+ew<dist[v]){
                    dist[v]=d+ew;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]); 
        }
        return ans;
    }
};