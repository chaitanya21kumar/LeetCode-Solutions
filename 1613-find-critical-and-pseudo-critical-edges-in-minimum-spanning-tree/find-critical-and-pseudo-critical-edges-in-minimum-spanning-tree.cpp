class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        int components;

        DSU(int n){
            parent.resize(n);
            components=n;
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int fp(int u){
            if(parent[u]==u) return u;
            return parent[u]=fp(parent[u]);
        }
        bool unite(int u,int v){
            int pu=fp(u);
            int pv=fp(v);
            if(pu!=pv){
                parent[pu]=pv;
                components--;
                return true;
            }
            else{
                return false;
            }
        }
    };
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[2]<b[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> ne;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int ew=edges[i][2];
            ne.push_back({u,v,ew,i});
        }
        sort(ne.begin(),ne.end(),comp);
        int N=ne.size();
        int ow=0; // original mst weight 
        DSU o1(n); // dsu object1
        for(int i=0;i<N;i++){
            int u=ne[i][0];
            int v=ne[i][1];
            int ew=ne[i][2];
            if(o1.unite(u,v)){
                ow+=ew;
            }
        }
        vector<int> c,pc; // critical, pseudo critical
        for(int i=0;i<N;i++){
            DSU o2(n); // dsu object2
            int sw=0; // skip weight
            for(int j=0;j<N;j++){
                int u=ne[j][0];
                int v=ne[j][1];
                int ew=ne[j][2];
                if(i==j) continue;
                if(o2.unite(u,v)){
                    sw+=ew;
                }
            }
            if(o2.components>1 || sw>ow) c.push_back(ne[i][3]);
            else{
                DSU o3(n);
                o3.unite(ne[i][0],ne[i][1]);
                int iw=ne[i][2]; // include weight
                for(int j=0;j<N;j++){
                    int u=ne[j][0];
                    int v=ne[j][1];
                    int ew=ne[j][2];
                    if(i==j) continue;
                    if(o3.unite(u,v)){
                        iw+=ew;
                    }
                }
                if(iw==ow) pc.push_back(ne[i][3]);
            }
        }
        return {c,pc};
    }
};