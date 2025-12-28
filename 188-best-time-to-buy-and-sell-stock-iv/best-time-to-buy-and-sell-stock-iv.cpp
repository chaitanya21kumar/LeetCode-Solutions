class Solution {
public:
    int f(int i,int b,int k,int n,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(i>=n || k<=0) return 0;
        if(dp[i][b][k]!=-1) return dp[i][b][k];
        int buy=0,notbuy=0,sell=0,notsell=0;
        if(b){
            buy=-prices[i]+f(i+1,0,k,n,prices,dp);
            notbuy=f(i+1,b,k,n,prices,dp);
            dp[i][b][k]=max(buy,notbuy);
        }
        else{
            sell=prices[i]+f(i+1,1,k-1,n,prices,dp);
            notsell=f(i+1,0,k,n,prices,dp);
            dp[i][b][k]=max(dp[i][b][k],max(sell,notsell));
        }

        return dp[i][b][k];
    }
    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));

        return f(0,1,k,n,prices,dp);
        
    }
};