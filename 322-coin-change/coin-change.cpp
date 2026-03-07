class Solution {
public:
    int f(int i,int amt,int n,vector<int>& coins,vector<vector<int>> &dp){

        if(i>=n && amt!=0) return 1e9;
        if(amt==0) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int pick=1e9;
        if(amt>=coins[i]){
            pick=1+f(i,amt-coins[i],n,coins,dp);
        }
        int notpick=f(i+1,amt,n,coins,dp);
        return dp[i][amt]=min(pick,notpick);

    }
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<vector<int>> dp(n+10,vector<int> (amount+10,-1));
        int ans=f(0,amount,n,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
        
    }
};