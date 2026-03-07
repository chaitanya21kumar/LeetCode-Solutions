class Solution {
public:
    int f(int cur,int par,vector<vector<int>> &adj,vector<bool>& hasApple){
        
        int time=0;
        for(auto &x:adj[cur]){
            if(x==par) continue;
            int time_from_this_child=f(x,cur,adj,hasApple);
            if(time_from_this_child>0 || hasApple[x]) time+=2+time_from_this_child;
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<vector<int>> adj(n);
        for(auto &x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return f(0,-1,adj,hasApple);
        
    }
};