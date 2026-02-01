class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> vis;
    void dfs(int i){
        vis[i]=1;
        for(auto &x:adj[i]){
            if(!vis[x]) dfs(x);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    int u=i;
                    int v=j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        vis.assign(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        return ans;

        
    }
};