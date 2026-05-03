class Solution {
public:
    unordered_map<int,vector<int>> adj;
    bool dfs(int u,int v,vector<int> &vis){
        vis[u]=1;
        if(u==v) return true;
        for(auto &x:adj[u]){
            if(!vis[x]){
                if(dfs(x,v,vis)) return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        int n=numCourses;
        for(auto &x:prerequisites){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
        }
        int qs=queries.size();
        vector<bool> ans(qs);
        for(int i=0;i<qs;i++){
            int u=queries[i][0],v=queries[i][1];
            vector<int> vis(n,0);
            ans[i]=dfs(u,v,vis);
        }
        return ans;

        
    }
};