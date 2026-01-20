class Solution {
public:
    int dp[20][20000];
    int f(int i,int amt,vector<int>& coins){
        if(amt==0) return 0;
        if(i>=coins.size() && amt!=0) return INT_MAX;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int pick=INT_MAX;
        int notpick=f(i+1,amt,coins);
        if(amt>=coins[i]){
            int x=f(i,amt-coins[i],coins);
            if(x!=INT_MAX) pick=1+x;
        }
        int ans=min(pick,notpick);
        return dp[i][amt]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int n=coins.size();
        int x=f(0,amount,coins);
        if(x==INT_MAX) return -1;
        return x; 
    }
};