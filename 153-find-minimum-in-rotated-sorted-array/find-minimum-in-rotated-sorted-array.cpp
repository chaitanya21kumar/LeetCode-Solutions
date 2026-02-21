class Solution {
public:
    int findMin(vector<int>& nums) {

        int n=nums.size();
        int ans=INT_MAX;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(nums[mid]>=nums[lo] && nums[mid]<=nums[hi]){
                ans=min(ans,nums[lo]);
                hi=mid-1;
            }
            else if(nums[lo]>nums[mid]){
                ans=min(ans,nums[mid]);
                hi=mid-1;
            }
            else if(nums[lo]<=nums[mid] && nums[mid]>nums[hi]){
                ans=min(ans,nums[lo]);
                lo=mid+1;
            }
        }
        return ans;
        
    }
};