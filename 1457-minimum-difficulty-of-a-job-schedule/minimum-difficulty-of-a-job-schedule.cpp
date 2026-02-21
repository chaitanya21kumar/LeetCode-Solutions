class Solution {
public:
    int f(int i,int d,int n,vector<int>& jd,vector<vector<int>> &dp){
        if(d==1){
            int ans=INT_MIN;
            for(int j=i;j<n;j++){
                ans=max(ans,jd[j]);
            }
            return ans;
        }
        if(dp[i][d]!=-1) return dp[i][d]; 
        int ans=INT_MAX;
        int cur_ans=INT_MIN;
        for(int j=i;j<=n-d;j++){
            cur_ans=max(cur_ans,jd[j]);
            ans=min(ans,cur_ans+f(j+1,d-1,n,jd,dp));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jd, int d) {

        int n=jd.size();
        if(d>n) return -1;
        vector<vector<int>> dp(n+10,vector<int> (d+10,-1));
        return f(0,d,n,jd,dp);
        
    }
};