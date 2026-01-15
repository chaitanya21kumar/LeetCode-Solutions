class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int f(int cur,int par,int n,vector<bool>& hasApple){

        int time=0;
        for(auto &child:adj[cur]){
            if(child==par) continue;
            int time_from_this_child=f(child,cur,n,hasApple);
            if(time_from_this_child>0 || hasApple[child]) time+=2+time_from_this_child;
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return f(0,-1,n,hasApple);

    }
};