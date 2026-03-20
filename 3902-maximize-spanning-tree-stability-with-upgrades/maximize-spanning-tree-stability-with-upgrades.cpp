struct DSU{

    vector<int> parent,rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }

    bool unite(int u,int v){
        int ulpu=find(u);
        int ulpv=find(v);
        
        if(ulpu==ulpv) return false;
        if(rank[ulpu]>rank[ulpv]){
            parent[ulpv]=ulpu;
        }
        else if(rank[ulpv]>rank[ulpu]){
            parent[ulpu]=ulpv;
        }
        else{
            parent[ulpu]=ulpv;
            rank[ulpv]++;
        }
        return true;
    }

};

class Solution {
public:
    bool possible(int n,vector<vector<int>>& edges,int k,int mid){
        DSU dsu(n);
        vector<vector<int>> upgrades;
        
        for(auto &x:edges){
            int u=x[0],v=x[1],s=x[2],m=x[3];
            if(m==1){
                if(s<mid) return false;
                dsu.unite(u,v);
            }
            else{
                if(s>=mid) dsu.unite(u,v);
                else if(2*s>=mid){
                    upgrades.push_back({u,v});
                }
            }
        }
        for(auto &x:upgrades){
            int u=x[0],v=x[1];
            if(dsu.find(u)!=dsu.find(v)){
                if(k<=0) return false;
                dsu.unite(u,v);
                k--;
            }
        }
        int root=dsu.find(0);
        for(int i=1;i<n;i++){
            if(dsu.find(i)!=root) return false;
        }
        return true;

    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo=1,hi=2*1e5;
        int ans=-1;
        DSU dsu(n);
        for(auto &x:edges){
            int u=x[0],v=x[1],s=x[2],m=x[3];
            if(m==1){
                if(dsu.find(u)==dsu.find(v)) return -1;
                dsu.unite(u,v);
            }
        }
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(possible(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
        
    }
};