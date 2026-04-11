class Solution {
public:
    unordered_map<int,vector<int>> adj;
    bool isbp(int cur,int col,vector<int> &color){

        color[cur]=col;
        for(auto &x:adj[cur]){
            if(color[x]==color[cur]) return false;
            else if(color[x]==-1){
                if(isbp(x,1-col,color)==false) return false;
            }
        }

        return true;

    }

    int bfs(int cur,int n){
        vector<int> vis(n);
        int l=1;
        vis[cur]=1;
        queue<int> q;
        q.push(cur);

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front();
                q.pop();
                for(auto &y:adj[x]){
                    if(!vis[y]){
                        vis[y]=1;
                        q.push(y);
                    }
                }
            }
            l++;
        }
        
        return l-1;
    }

    int f(int cur,vector<int> &vis,vector<int> &levels){
        vis[cur]=1;
        int mx=levels[cur];

        for(auto &x:adj[cur]){
            if(!vis[x]){
                mx=max(mx,f(x,vis,levels));
            }
        }

        return mx;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {

        for(auto &x:edges){
            int u=x[0]-1;
            int v=x[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(isbp(i,0,color)==false) return -1;
            }
        }
        vector<int> levels(n,0);
        for(int i=0;i<n;i++){
            levels[i]=bfs(i,n);
        }

        int ans=0;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans+=f(i,vis,levels);
            }
        }

        return ans;
        
    }
};