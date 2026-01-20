class Solution {
public:
    int dp[20000];
    int f(vector<int>& coins, int amt){
        if(amt==0) return 0;
        if(amt<0) return INT_MAX;
        if(dp[amt]!=-1) return dp[amt];
        int x=INT_MAX;
        for(auto &c:coins){
            if(amt>=c){
                int y=f(coins,amt-c);
                if(y!=INT_MAX) x=min(x,1+y);
            }
        }
        return dp[amt]=x;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int n=coins.size();
        int ans=f(coins,amount);
        if(ans!=INT_MAX) return ans;
        return -1;

        
    }
};