class Solution {
public:
    int findMin(vector<int>& nums) {

        int n=nums.size();
        int lo=0,hi=n-1;
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(nums[mid]>=nums[lo] && nums[mid]>nums[hi]){
                lo=mid+1;
            }
            else if(nums[lo]>nums[mid]){
                ans=min(ans,nums[mid]);
                hi=mid-1;
            }
            else if(nums[mid]>=nums[lo] && nums[hi]>=nums[mid]){
                ans=min(ans,nums[lo]);
                hi=mid-1;
            }
        }
        return ans;


        
    }
};