class Solution {
public:
    int f(int i,int n,vector<int> &dp){
        if(i>n) return 0;
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        ans=f(i+1,n,dp)+f(i+2,n,dp);
        return dp[i]=ans;
    }
    int climbStairs(int n) {

        vector<int> dp(n,-1);
        return f(0,n,dp);
        
    }
};