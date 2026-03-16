class Solution {
public:
    typedef long long int ll;
    ll mn=LLONG_MIN/2;
    ll f(int i,int t,int n,vector<vector<ll>> &dp,vector<int> &nums){
        if(i>=n){
            return mn;
        }
        if(dp[i][t]!=LLONG_MIN) return dp[i][t];
        ll take=mn;
        ll skip=mn;
        if(t==0) skip=f(i+1,t,n,dp,nums);
        if(t==3) take=nums[i];

        if(i+1<n){
            ll curr=nums[i];
            ll next=nums[i+1];

            if(t==0){
                if(next>curr) take=max(take,curr+f(i+1,1,n,dp,nums));
            }
            else if(t==1){
                if(next>curr) take=max(take,curr+f(i+1,1,n,dp,nums));
                else if(curr>next) take=max(take,curr+f(i+1,2,n,dp,nums));
            }
            else if(t==2){
                if(curr>next) take=max(take,curr+f(i+1,2,n,dp,nums));
                else if(next>curr) take=max(take,curr+f(i+1,3,n,dp,nums));
            }
            else if(t==3){
                if(next>curr) take=max(take,curr+f(i+1,3,n,dp,nums));
            }
        }
        return dp[i][t]=max(skip,take);
    }
    long long maxSumTrionic(vector<int>& nums) {

        ll n=nums.size();
        vector<vector<ll>> dp(n,vector<ll> (4,LLONG_MIN));
        return f(0,0,n,dp,nums);
        
    }
};