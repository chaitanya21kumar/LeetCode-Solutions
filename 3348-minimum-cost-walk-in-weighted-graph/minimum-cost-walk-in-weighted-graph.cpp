class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int u,int v){
        parent[v]=u;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        parent.resize(n);
        vector<int> cost(n,-1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            
            int pu=find(u);
            int pv=find(v);

            Union(pu,pv);
            cost[pu]&=cost[pv];
            cost[pu]&=w;

        }

        vector<int> ans(query.size());
        for(int i=0;i<query.size();i++){
            int u=query[i][0];
            int v=query[i][1];

            int pu=find(u);
            int pv=find(v);
            if(pu!=pv) ans[i]=-1;
            else ans[i]=cost[pu];
        }

        return ans;

    }
};