class Solution {
public:
    int f(int i,int p,vector<vector<int>> &adj,int k){
        if(k<0) return 0;
        int c=1;

        for(auto &x:adj[i]){
            if(x==p) continue;
            c+=f(x,i,adj,k-1);
        }
        
        return c;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        int n=edges1.size()+1;
        int m=edges2.size()+1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for(auto &x:edges1){
            int u=x[0],v=x[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(auto &x:edges2){
            int u=x[0],v=x[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int mx=INT_MIN;
        for(int i=0;i<m;i++){
            int x=f(i,-1,adj2,k-1);
            mx=max(mx,x);
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int x=f(i,-1,adj1,k);
            ans[i]=x+mx;
        }

        return ans;

    }
};