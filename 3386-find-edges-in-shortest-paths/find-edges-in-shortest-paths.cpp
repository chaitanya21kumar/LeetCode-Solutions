class Solution {
public:
    typedef long long int ll;
    typedef pair<ll,ll> p;
    vector<ll> f(ll src,ll n,ll m,vector<vector<pair<ll,ll>>> &adj){
        vector<ll> d(n,1e10);
        d[src]=0;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,src});

        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            ll dist=x.first;
            ll node=x.second;

            if(dist>d[node]) continue;
            for(auto &y:adj[node]){
                ll v=y.first;
                ll w=y.second;
                if(dist+w<d[v]){
                    d[v]=dist+w;
                    pq.push({d[v],v});
                }
            }
        }
        return d;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {

        ll m=edges.size();
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto &x:edges){
            ll u=x[0];
            ll v=x[1];
            ll w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<ll> fs=f(0,n,m,adj); // from source
        vector<ll> fd=f(n-1,n,m,adj); // from destination
        vector<bool> ans(m,false);
        if(fs[n-1]==1e10) return ans;
        for(int i=0;i<m;i++){
            ll u=edges[i][0];
            ll v=edges[i][1];
            ll w=edges[i][2];
            
            ll dfs=fs[u]; // dist from src
            ll dfd=fd[v]; // dist from dest

            ll d1=dfs+w+dfd;

            ll dfsr=fs[v]; // reverse
            ll dfdr=fd[u];

            ll d2=(ll)dfsr+w+dfdr; 

            if(d1==fs[n-1] || d2==fs[n-1]){
                ans[i]=true;
            }
        }
        return ans;
        
    }
};