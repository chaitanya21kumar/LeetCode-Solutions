class Solution {
public:
    typedef long long int ll;
    ll dp[350][350];
    int f(int mi,int l,int n,int m,vector<int>& nums, vector<int>& multipliers){
        if(mi==m) return 0;
        if(dp[mi][l]!=-1e9) return dp[mi][l];
        ll ri=n-1-(mi-l);
        ll sl=1LL*nums[l]*multipliers[mi]+f(mi+1,l+1,n,m,nums,multipliers);
        ll sr=1LL*nums[ri]*multipliers[mi]+f(mi+1,l,n,m,nums,multipliers);
        return dp[mi][l]=max(sl,sr);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {

        ll n=nums.size();
        ll m=multipliers.size();
        for(ll i=0;i<350;i++){
            for(ll j=0;j<350;j++){
                dp[i][j]=-1e9;
            }
        }
        return f(0,0,n,m,nums,multipliers);
        
    }
};