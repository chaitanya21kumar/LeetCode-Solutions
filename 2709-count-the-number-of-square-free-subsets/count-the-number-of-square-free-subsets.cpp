class Solution {
public:
    typedef long long int ll;
    #define  M 1000000007
    vector<int> primes={2,3,5,7,11,13,17,19,23,29};
    vector<int> masks;
    ll f(int i,int mask,vector<int>& nums,vector<vector<int>> &dp){
        if(i==nums.size()) return 1;
        if(dp[i][mask]!=-1) return dp[i][mask];
        ll notpick=f(i+1,mask,nums,dp);
        ll pick=0;
        ll cur_mask=masks[nums[i]];
        if(cur_mask!=-1 && ( (cur_mask & mask)==0 )){
            pick=f(i+1,mask | cur_mask,nums,dp);
        }
        return dp[i][mask]=(pick+notpick)%M;
    }
    int squareFreeSubsets(vector<int>& nums) {

        ll n=nums.size();
        masks.assign(35,0);
        vector<vector<int>> dp(n+10,vector<int> (1030,-1));
        for(int i=1;i<=30;i++){
            int num=i;
            int mask=0;
            bool check=0;
            for(int j=0;j<10;j++){
                if(num%primes[j]==0){
                    if(num%(primes[j]*primes[j])==0){
                        masks[i]=-1;
                        check=1;
                        break;
                    }
                    mask=mask | (1<<j);
                }
            }
            if(check==0){
                masks[i]=mask;
            }
        }

        ll ans=f(0,0,nums,dp);
        ans=(ans-1+M)%M;
        return ans;
        
    }
};