class Solution {
public:
    int f(int i,int b,int n,vector<int>&prices,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[b][i]!=-1) return dp[b][i];
        int buy=0,notbuy=0,sell=0,notsell=0;
        if(b){
            buy=-prices[i]+f(i+1,0,n,prices,dp);
            notbuy=0+f(i+1,1,n,prices,dp);
        }
        else{
            sell=prices[i]+f(i+1,1,n,prices,dp);
            notsell=f(i+1,0,n,prices,dp);
        }
        int ans=max({buy,notbuy,sell,notsell});
        return dp[b][i]=ans;
    }
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        vector<vector<int>> dp(2,vector<int> (n,-1));

        return f(0,1,n,prices,dp);
        
    }
};