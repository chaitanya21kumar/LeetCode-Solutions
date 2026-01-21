class Solution {
public:
    int dp[1001][101][3];
    int f(int i,int b,int k,int n,vector<int>& prices){
        if(i>=n || k==0) return 0;
        if(dp[i][k][b]!=-1) return dp[i][k][b];
        int buy=0,sell=0,skip=0;
        if(b){
            buy=-prices[i]+f(i+1,0,k,n,prices);
        }
        if(!b){
            sell=+prices[i]+f(i+1,1,k-1,n,prices);
        }
        skip=f(i+1,b,k,n,prices);
        return dp[i][k][b]=max({buy,sell,skip});
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int n=prices.size();
        return f(0,1,k,n,prices);
    }
};