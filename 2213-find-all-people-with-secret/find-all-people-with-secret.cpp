class Solution {
public:
    typedef pair<int,int> p;
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int fp) {

        vector<vector<pair<int,int>>> adj(n);
        vector<int> et(n,INT_MAX);

        for(auto &x:m){
            int u=x[0];
            int v=x[1];
            int t=x[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        pq.push({0,fp});

        et[0]=0;
        et[fp]=0;

        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int t=x.first;
            int node=x.second;

            if(et[node]<t) continue;
            for(auto &y:adj[node]){
                int mt=y.second;
                int v=y.first;
                if(mt>=t && et[v]>mt){
                    et[v]=mt;
                    pq.push({mt,v});
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(et[i]!=INT_MAX){
                ans.push_back(i);
            }
        }

        return ans;

    }
};