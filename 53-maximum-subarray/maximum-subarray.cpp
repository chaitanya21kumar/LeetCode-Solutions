class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        if(n==1) return nums[0];
        int ans=INT_MIN,s=0,mx=INT_MIN;
        int zp=0;
        for(int i=0;i<n;i++){
            if(s+nums[i]>=0) s+=nums[i];
            else s=0;
            ans=max(ans,s);
            mx=max(mx,nums[i]);
            if(nums[i]==0) zp=1;
        }
        if(zp==0 && ans==0) return mx;
        return ans;
        
    }
};