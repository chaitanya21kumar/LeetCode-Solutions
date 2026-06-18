class Solution {
public:
    typedef pair<int,int> p;
    typedef long long int ll;
    vector<int> countOfPairs(int n, int x, int y) {

        vector<int> ans(n);
        vector<vector<ll>> adj(n+1);
        for(ll i=1;i<n;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        if(x!=y){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(ll i=1;i<=n;i++){
            vector<ll> dist(n+1,1e7);
            priority_queue<p,vector<p>,greater<p>> pq;
            pq.push({0,i});
            dist[i]=0;
            while(!pq.empty()){
                auto x=pq.top();
                pq.pop();
                ll d=x.first;
                ll node=x.second;
                if(dist[node]<d) continue;
                for(auto &y:adj[node]){
                    if(dist[y]>d+1){
                        dist[y]=d+1;
                        pq.push({dist[y],y});
                    }
                }
            }
            for(int k=1;k<=n;k++){
                if(k!=i && dist[k]!=1e7){
                    ans[dist[k]-1]++;
                }
            }
        }
        return ans;


        
    }
};