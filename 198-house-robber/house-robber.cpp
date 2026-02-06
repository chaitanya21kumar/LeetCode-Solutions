class Solution {
public:
    vector<int> dp;
    int f(int i,int n,vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=0;
        int notpick=0;
        pick=nums[i]+f(i+2,n,nums);
        notpick=f(i+1,n,nums);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n+1,-1);
        return f(0,n,nums);
        
    }
};