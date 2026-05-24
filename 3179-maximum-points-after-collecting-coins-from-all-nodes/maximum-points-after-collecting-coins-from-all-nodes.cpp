class Solution {
public:
    int f(int i,int par,int s,int n,int k,vector<vector<int>> &adj,vector<vector<int>> &dp,vector<int> &coins){
        if(i==n) return 0;
        if(s>=14) s=14;
        if(dp[i][s]!=-1) return dp[i][s];

        int cc=coins[i]>>s;
        int p1=cc-k,p2=cc/2;
        for(auto &x:adj[i]){
            if(x!=par){
                p1+=f(x,i,s,n,k,adj,dp,coins);
                p2+=f(x,i,s+1,n,k,adj,dp,coins);
            }
        }
        return dp[i][s]=max(p1,p2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {

        int n=coins.size();
        vector<vector<int>> adj(n);
        for(auto &x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> dp(n,vector<int> (15,-1));

        return f(0,-1,0,n,k,adj,dp,coins); // {i,parent,shifts,n,k,adj,dp}
        
    }
};