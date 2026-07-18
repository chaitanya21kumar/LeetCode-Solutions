class Solution {
public:
    int f(int i,int cap,int n,vector<int> &stones,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][cap]!=-1) return dp[i][cap];
        int notpick=f(i+1,cap,n,stones,dp);
        int pick=0;
        if(cap>=stones[i]){
            pick=stones[i]+f(i+1,cap-stones[i],n,stones,dp);
        }
        return dp[i][cap]=max(pick,notpick);
    }
    int lastStoneWeightII(vector<int>& stones) {

        int n=stones.size();
        int ts=0;
        for(int i=0;i<n;i++){
            ts+=stones[i];
        }
        vector<vector<int>> dp(n+1,vector<int> (ts+10,-1));
        int s2=f(0,ts/2,n,stones,dp);
        int s1=ts-s2;
        return s1-s2;
        
    }
};