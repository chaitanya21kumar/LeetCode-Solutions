class Solution {
public:
    int f(int i,int n,vector<int>& coins,int amount,vector<vector<int>> &dp){
        if(i==n){
            if(amount==0) return 0;
            return INT_MAX;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=INT_MAX;
        int notpick=INT_MAX;
        if(amount>=coins[i]){
            int x=f(i,n,coins,amount-coins[i],dp);
            if(x!=INT_MAX){
                pick=1+x;
            }
        }
        int y=f(i+1,n,coins,amount,dp);
        if(y!=INT_MAX){
            notpick=y;
        }
        return dp[i][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<vector<int>> dp(n+10,vector<int> (amount+10,-1));
        int x=f(0,n,coins,amount,dp);
        if(x==INT_MAX) return -1;
        return x;
        
    }
};