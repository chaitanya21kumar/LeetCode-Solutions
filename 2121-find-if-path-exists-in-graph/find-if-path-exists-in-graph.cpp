class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        queue<int> q;
        q.push(source);
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        vis[source]=1;
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                if(x==destination) return true;
                for(auto &y:adj[x]){
                    if(!vis[y]){
                        vis[y]=1;
                        q.push(y);
                    }
                }
            }

        }
        return false;
        
    }
};