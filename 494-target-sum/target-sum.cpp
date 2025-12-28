class Solution {
public:
    int offset=1e4;
    int f(int i,int ans,int t,int n,vector<int> &nums,vector<vector<int>> &dp){
        if(i==n && ans==t) return 1;
        if(i>=n && ans!=t) return 0;
        if(dp[i][ans+offset]!=-1) return dp[i][ans+offset];
        int pos=f(i+1,ans+nums[i],t,n,nums,dp);
        int neg=f(i+1,ans-nums[i],t,n,nums,dp);

        return dp[i][ans+offset]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (target+1e5,-1));

        return f(0,0,target,n,nums,dp);
        
    }
};