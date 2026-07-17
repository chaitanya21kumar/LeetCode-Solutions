class Solution {
public:
    int f(int i,vector<string>& strs,int m,int n,vector<vector<vector<int>>> &dp){
        if(i==strs.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int pick=0,notpick=0;
        notpick=f(i+1,strs,m,n,dp);
        int c0=0,c1=0;
        for(int j=0;j<strs[i].size();j++){
            if(strs[i][j]=='0') c0++;
            else c1++;
        }
        if(m>=c0 && n>=c1){
            pick=1+f(i+1,strs,m-c0,n-c1,dp);
        }
        int ans=max(pick,notpick);
        return dp[i][m][n]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>> (m+1,vector<int> (n+1,-1)));
        return f(0,strs,m,n,dp);
        
    }
};