class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n+1);
        for(auto &x:dislikes){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++){
            if(c[i]==0){
                c[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    auto x=q.front();
                    q.pop();
                    for(auto &y:adj[x]){
                        if(c[y]==0){
                            c[y]=-1*c[x];
                            q.push(y);
                        }
                        else if(c[x]==c[y]) return false;
                    }
                }
            }
        }
        return true;
    }
};