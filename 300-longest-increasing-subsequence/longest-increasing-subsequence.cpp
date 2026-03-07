class Solution {
public:
    int f(int i,int pidx,int n,vector<int>& nums,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][pidx+1]!=-1) return dp[i][pidx+1];
        int pick=INT_MIN,notpick=INT_MIN;
        notpick=f(i+1,pidx,n,nums,dp);
        if(pidx==-1 || nums[i]>nums[pidx]){
            pick=1+f(i+1,i,n,nums,dp);
        }
        return dp[i][pidx+1]=max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> dp(n+10,vector<int> (n+10,-1));
        return f(0,-1,n,nums,dp);
        
    }
};