class Solution {
public:
    #define M 1000000007
    int f(int c,int t,int k,vector<vector<int>> &dp){
        if(k==0){
            if(c==t) return 1;
            else return 0;
        }
        if(abs(c-t)>k) return 0;
        int sc=c+1000;
        if(dp[sc][k]!=-1) return dp[sc][k];
        int left=f(c-1,t,k-1,dp);
        int right=f(c+1,t,k-1,dp);
        return dp[sc][k]=(left+right)%M;
    }
    int numberOfWays(int sp, int ep, int k) {

        vector<vector<int>> dp(5000,vector<int> (2000,-1));
        return f(sp,ep,k,dp);
        
    }
};