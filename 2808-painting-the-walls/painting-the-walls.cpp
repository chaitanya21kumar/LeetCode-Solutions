class Solution {
public:
    int f(int i,int n,vector<int>& cost, vector<int>& time,vector<vector<int>> &dp){
        if(n<=0) return 0;
        if(i>=cost.size() && n>0) return 1e9;
        if(dp[i][n]!=-1) return dp[i][n];

        int pick=cost[i]+f(i+1,n-1-time[i],cost,time,dp);
        int notpick=f(i+1,n,cost,time,dp);

        return dp[i][n]=min(pick,notpick);

    }
    int paintWalls(vector<int>& cost, vector<int>& time) {

        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return f(0,n,cost,time,dp);
        
    }
};