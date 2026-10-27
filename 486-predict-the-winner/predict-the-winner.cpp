class Solution {
public:
    int f(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int ti=nums[i]+min(f(i+2,j,nums,dp),f(i+1,j-1,nums,dp));
        int tj=nums[j]+min(f(i+1,j-1,nums,dp),f(i,j-2,nums,dp));
        return max(ti,tj);
    }
    bool predictTheWinner(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> dp(n+10,vector<int> (n+10,-1));
        int ts=accumulate(nums.begin(),nums.end(),0);
        int p1=f(0,n-1,nums,dp);
        int p2=ts-p1;
        if(p1>=p2) return true;
        return false;
        
    }
};