class Solution {
public:
    int ans=INT_MIN;
    unordered_map<int,int> m;

    bool dfsb(int cur,int t,vector<int> &vis,unordered_map<int,vector<int>> &adj){
        vis[cur]=1;
        m[cur]=t;

        if(cur==0){
            return true;
        }

        for(auto &x:adj[cur]){
            if(!vis[x] && dfsb(x,t+1,vis,adj)==true) return true;
        }

        m.erase(cur);
        return false;

    }

    void dfsa(int cur,int t,vector<int> &vis,unordered_map<int,vector<int>> &adj,int income,vector<int>& amount){

        vis[cur]=1;

        if(m.find(cur)==m.end() || t<m[cur]){
            income+=amount[cur];
        }
        else if(t==m[cur]){
            income+=(amount[cur]/2);
        }

        if(adj[cur].size()==1 && cur!=0){
            ans=max(ans,income);
        }

        for(auto &x:adj[cur]){
            if(!vis[x]){
                dfsa(x,t+1,vis,adj,income,amount);
            }
        }

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        unordered_map<int,vector<int>> adj;

        for(auto &x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visb(n,0);
        vector<int> visa(n,0);

        dfsb(bob,0,visb,adj);
        dfsa(0,0,visa,adj,0,amount);

        return ans;

    }
};