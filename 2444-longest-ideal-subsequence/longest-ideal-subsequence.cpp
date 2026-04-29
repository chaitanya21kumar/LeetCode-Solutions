class Solution {
public:
    int f(int i,string &s,int n,int k,int lc,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][lc+1]!=-1) return dp[i][lc+1];

        int cc=s[i]-'a'+1;
        int pick=0;
        if(lc==-1 || abs(lc-cc)<=k){
            pick=1+f(i+1,s,n,k,cc,dp);
        }
        int notpick=f(i+1,s,n,k,lc,dp);

        return dp[i][lc+1]=max(pick,notpick);
    }
    int longestIdealString(string s, int k) {

        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (28,-1));
        return f(0,s,n,k,-1,dp);
        
    }
};