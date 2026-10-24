class Solution {
public:
    int f(int i,int r,vector<int>& nums,int n,vector<vector<int>> &dp){

        if(i>=n){
            if(r==0) return 0;
            return -1e9;
        }
        if(dp[i][r]!=-1) return dp[i][r];
        int take=nums[i]+f(i+1,(r+nums[i])%3,nums,n,dp);
        int nottake=f(i+1,r,nums,n,dp);
        return dp[i][r]=max(take,nottake);
        
    }
    int maxSumDivThree(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (3,-1));
        return f(0,0,nums,n,dp);
        
    }
};