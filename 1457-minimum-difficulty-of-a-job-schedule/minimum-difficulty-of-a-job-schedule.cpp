class Solution {
public:
    int f(int i,int d,int n,vector<vector<int>> &dp,vector<int>& jd){
        if(d==1){
            int ans=INT_MIN;
            for(int j=i;j<n;j++) ans=max(ans,jd[j]);
            return ans;
        }
        if(dp[i][d]!=-1) return dp[i][d];
        int mn=INT_MIN;
        int ansi=1e9;
        for(int j=i;j<=n-d;j++){
            mn=max(mn,jd[j]);
            ansi=min(ansi,mn+f(j+1,d-1,n,dp,jd));
        }
        return dp[i][d]=ansi;
    }
    int minDifficulty(vector<int>& jd, int d) {

        int n=jd.size();
        vector<vector<int>> dp(n+10,vector<int> (d+10,-1));
        if(d>n) return -1;
        return f(0,d,n,dp,jd);
        
    }
};