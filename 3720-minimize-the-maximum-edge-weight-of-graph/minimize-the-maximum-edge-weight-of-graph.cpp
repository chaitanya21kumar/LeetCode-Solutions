class Solution {
public:
    bool poss(int n,int mid,vector<vector<vector<int>>> &adj){
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int c=1;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(int i=0;i<adj[x].size();i++){
                int v=adj[x][i][0];
                int w=adj[x][i][1];
                if(w<=mid && !vis[v]){
                    vis[v]=1;
                    q.push(v);
                    c++;
                }
            }
        }
        return c==n;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {

        vector<vector<vector<int>>> adj(n);
        int mx=0;
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            vector<int> temp;
            temp.push_back(u);
            temp.push_back(w);
            adj[v].push_back(temp);
            if(mx<w) mx=w;
        }
        int lo=1,hi=mx;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(poss(n,mid,adj)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};