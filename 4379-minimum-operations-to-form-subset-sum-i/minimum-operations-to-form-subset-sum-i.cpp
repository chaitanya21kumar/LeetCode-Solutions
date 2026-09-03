class Solution {
public:
    typedef long long int ll;
    ll f(int i,int n,int s,vector<int> &nums,vector<vector<ll>> &dp){
        if(s==0) return 0;
        if(s<0 || i>=n) return 1e9;
        if(dp[i][s]!=-1) return dp[i][s];

        ll mnops=f(i+1,n,s,nums,dp);
        int x=nums[i];
        ll val=x;
        ll cost=0;
        while(val<=s){
            mnops=min(mnops,cost+f(i+1,n,s-val,nums,dp));
            val*=2;
            cost++;
        }
        cost=0;
        val=x;
        while(val>0){
            val/=2;
            cost++;
            if(val>0 && val<=s){
                mnops=min(mnops,cost+f(i+1,n,s-val,nums,dp));
            }
        }
        return dp[i][s]=mnops;
    }
    int minOperations(vector<int>& nums, int sum) {

        int n=nums.size();
        vector<vector<ll>> dp(n+10,vector<ll> (sum+10,-1));
        ll ans=f(0,n,sum,nums,dp);
        if(ans>=1e9) return -1;
        return ans;
        
    }
};