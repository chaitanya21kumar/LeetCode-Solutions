class Solution {
public:
    typedef long long int ll;
    #define M 1000000007;
    int f(int cs,int cu,int n,int g,int k,vector<vector<int>> &dp){
        if(cs==g){
            if(cu==n) return 1;
            return 0;
        }
        if(dp[cs][cu]!=-1) return dp[cs][cu];
        ll ans=0;

        if(n>cu){
            ans=(ans+(ll)(n-cu)*f(cs+1,cu+1,n,g,k,dp))%M;
        }
        
        if(cu>k){
            ans=(ans+(ll)(cu-k)*f(cs+1,cu,n,g,k,dp))%M;
        }

        return dp[cs][cu]=ans%M;

    }
    int numMusicPlaylists(int n, int goal, int k) {

        vector<vector<int>> dp(goal+10,vector<int> (n+10,-1));
        return f(0,0,n,goal,k,dp);
        
    }
};