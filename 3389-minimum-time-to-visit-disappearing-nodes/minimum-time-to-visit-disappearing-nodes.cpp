class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        typedef pair<int,int> p;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &x:edges){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> ans(n,1000000);
        ans[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int dist=x.first;
            int node=x.second;
            if(dist>ans[node]) continue;
            for(auto &y:adj[node]){
                int v=y.first;
                int w=y.second;
                int c=disappear[v];
                if(dist+w<disappear[v] && dist+w<ans[v]){
                    ans[v]=dist+w;
                    pq.push({dist+w,v});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==1000000) ans[i]=-1;
        }
        return ans;
        
    }
};