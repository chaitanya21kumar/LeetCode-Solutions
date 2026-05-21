class Solution {
public:
    #define M 1000000007
    int f(int cn,int n,int k,int t,vector<vector<int>> &dp){
        if(t==0 && cn==n+1) return 1;
        if(cn>n || t<0) return 0;
        if(dp[cn][t]!=-1) return dp[cn][t];
        int ans=0;
        for(int i=1;i<=k;i++){
            if(t>=i){
                ans=(ans+f(cn+1,n,k,t-i,dp))%M;
            }
        }
        return dp[cn][t]=ans;
    }
    int numRollsToTarget(int n, int k, int t) {

        vector<vector<int>> dp(n+1,vector<int> (t+10,-1));
        return f(1,n,k,t,dp); // {cur_dice,n,k,target}
        
    }
};