class Solution {
public:
    void dfs(int i,int p,int color,vector<vector<int>> &adj,vector<int> &col,vector<int> &c){

        col[i]=color;
        c[color]++;

        for(auto &x:adj[i]){
            if(x==p) continue;
            dfs(x,i,color^1,adj,col,c);
        }

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int n=edges1.size()+1;
        int m=edges2.size()+1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        vector<int> col1(n);
        vector<int> col2(m);

        vector<int> c1(2);
        vector<int> c2(2);

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

        vector<int> ans(n);

        dfs(0,-1,0,adj1,col1,c1);
        dfs(0,-1,0,adj2,col2,c2);

        int mx=max(c2[0],c2[1]);

        for(int i=0;i<n;i++){
            ans[i]=c1[col1[i]]+mx;
        }

        return ans;

        
    }
};