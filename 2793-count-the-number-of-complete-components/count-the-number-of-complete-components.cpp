class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n);
        queue<int> q;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
                int v=0,e=0;
                while(!q.empty()){
                    auto x=q.front();
                    q.pop();
                    
                    v++;
                    e+=(adj[x].size());
                    for(auto &y:adj[x]){
                        if(!vis[y]){
                            vis[y]=1;
                            q.push(y);
                        }
                    }

                }

                if(e/2 == v*(v-1)/2) ans++;
            }
        }
        return ans;
        
    }
};