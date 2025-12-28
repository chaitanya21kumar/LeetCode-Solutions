class Solution {
public:
    int f(int i,int amt,int n,vector<int> &coins,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(amt==0) return 1;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int pick=0,notpick=0;
        if(coins[i]<=amt){
            pick=f(i,amt-coins[i],n,coins,dp);
        }
        notpick=f(i+1,amt,n,coins,dp);
        return dp[i][amt]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        return f(0,amount,n,coins,dp);
        
    }
};