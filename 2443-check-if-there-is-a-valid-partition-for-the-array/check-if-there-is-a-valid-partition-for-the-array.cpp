class Solution {
public:
    bool f(int i,int n,vector<int> &dp,vector<int>& nums){
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        bool ans=false;

        if(i+1<n && nums[i]==nums[i+1]){
            ans=ans||f(i+2,n,dp,nums);
        }
        if(i+2<n){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                ans=ans||f(i+3,n,dp,nums);
            }
            if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
                ans=ans||f(i+3,n,dp,nums);
            }
        }
        return dp[i]=ans;
    }
    bool validPartition(vector<int>& nums) {

        int n=nums.size();
        vector<int> dp(n+10,-1);
        return f(0,n,dp,nums);
        
    }
};