class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& sp, int sn, int en) {

        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<e.size();i++){
            int u=e[i][0];
            int v=e[i][1];
            double csp=sp[i];
            adj[u].push_back({v,csp});
            adj[v].push_back({u,csp});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,sn});
        vector<double> v(n,0.0);
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            double cnp=x.first; // current node prob
            int cn=x.second;

            if(cn==en) return cnp;
            if(cnp<v[cn]) continue;
            for(auto &y:adj[cn]){
                int nn=y.first;
                double nnp=y.second;
                double n_p=cnp*nnp;
                if(n_p>v[nn]){
                    v[nn]=n_p;
                    pq.push({n_p,nn});
                }
            }
        }
        return 0.0;
        
    }
};