class DSU{

    private:
    vector<int> parent;
    vector<int> rank;
    int components;

    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        components=n;
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int xp=find(x);
        int yp=find(y);

        if(xp==yp){
            return;
        }
        else if(rank[xp]>rank[yp]){
            parent[yp]=xp;
        }
        else if(rank[yp]>rank[xp]){
            parent[xp]=yp;
        }
        else{
            parent[xp]=yp;
            rank[yp]++;
        }
        components--;
    }

    bool isSingle(){
        return components==1;
    }

};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        auto lambda=[&](vector<int> &v1,vector<int> &v2){
            return v1[0]>v2[0];
        };

        sort(edges.begin(),edges.end(),lambda);
        DSU alice(n);
        DSU bob(n);

        int ae=0;

        for(auto &x:edges){
            int t=x[0];
            int u=x[1];
            int v=x[2];

            if(t==3){
                bool a=false;

                if(alice.find(u)!=alice.find(v)){
                    alice.Union(u,v);
                    a=true;
                }
                if(bob.find(u)!=bob.find(v)){
                    bob.Union(u,v);
                    a=true;
                }
                if(a) ae++;
            }
            else if(t==2){
                if(bob.find(u)!=bob.find(v)){
                    bob.Union(u,v);
                    ae++;
                }
            }
            else{
                if(alice.find(u)!=alice.find(v)){
                    alice.Union(u,v);
                    ae++;
                }
            }
        }

        if(alice.isSingle() && bob.isSingle()) return edges.size()-ae;
        return -1;
        
    }
};