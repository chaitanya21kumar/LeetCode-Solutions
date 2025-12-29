class Solution {
public:
    int dp[350][350];
    int f(vector<int> &nums,int left,int right){
        if(left>right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int res=0;
        for(int k=left+1;k<=right-1;k++){
            int ans=nums[left]*nums[k]*nums[right]+f(nums,left,k)+f(nums,k,right);
            res=max(res,ans);
        }

        return dp[left][right]=res;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        

        nums.push_back(1);
        nums.insert(nums.begin()+0,1);
        int n=nums.size();
        return f(nums,0,n-1);

        
    }
};