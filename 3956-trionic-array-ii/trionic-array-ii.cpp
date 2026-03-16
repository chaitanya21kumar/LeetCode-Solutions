class Solution {
public:
    typedef long long int ll;
    ll f(int i,int t,int n,vector<vector<ll>> &dp,vector<int> &nums){
        if(i>=n){
            if(t==3) return 0;
            return LLONG_MIN/2;
        }
        if(dp[i][t]!=LLONG_MIN) return dp[i][t];
        ll take=LLONG_MIN/2;
        ll skip=LLONG_MIN/2;

        if(t==0) skip=f(i+1,t,n,dp,nums);
        if(t==3) take=nums[i];

        if(i+1<n){
            ll curr=nums[i];
            ll next=nums[i+1];

            if(t==0 && next>curr){
                take=max(take,curr+f(i+1,1,n,dp,nums));
            }
            else if(t==1 && next>curr){
                take=max(take,curr+f(i+1,1,n,dp,nums));
            }
            else if(t==1 && curr>next){
                take=max(take,curr+f(i+1,2,n,dp,nums));
            }
            else if(t==2 && curr>next){
                take=max(take,curr+f(i+1,2,n,dp,nums));
            }
            else if(t==2 && next>curr){
                take=max(take,curr+f(i+1,3,n,dp,nums));
            }
            else if(t==3 && next>curr){
                take=max(take,curr+f(i+1,3,n,dp,nums));
            }
        }
        return dp[i][t]=max(take,skip);
    }
    long long maxSumTrionic(vector<int>& nums) {

        ll n=nums.size();
        vector<vector<ll>> dp(n,vector<ll> (4,LLONG_MIN));
        return f(0,0,n,dp,nums);
        
    }
};