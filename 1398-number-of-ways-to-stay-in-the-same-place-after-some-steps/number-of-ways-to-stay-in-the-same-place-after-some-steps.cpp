class Solution {
public:
    #define M 1000000007
    int f(int i,int s,int l ,int r,vector<vector<int>> &dp){
        if(s==0){
            if(i==0) return 1;
            else return 0;
        }
        if(i<l || i>r) return 0;
        if(dp[i][s]!=-1) return dp[i][s];
        int left=f(i-1,s-1,l,r,dp)%M;
        int right=f(i+1,s-1,l,r,dp)%M;
        int stay=f(i,s-1,l,r,dp)%M;
        return dp[i][s]=((left+right)%M+stay)%M;
    }
    int numWays(int s, int n) {

        vector<vector<int>> dp(600,vector<int> (600,-1));
        return f(0,s,0,n-1,dp);
        
    }
};