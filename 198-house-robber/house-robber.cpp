class Solution {
public:
    int dp[110];
    int f(int i,int n,vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=0,notpick=0;
        pick=nums[i]+f(i+2,n,nums);
        notpick=f(i+1,n,nums);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return f(0,n,nums);
    }
};