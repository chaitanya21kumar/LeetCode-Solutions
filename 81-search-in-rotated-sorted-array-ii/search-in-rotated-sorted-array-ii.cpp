class Solution {
public:
    bool search(vector<int>& nums, int t) {

        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(nums[mid]==t) return true;
            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                lo++;hi--;
                continue;
            }
            else if(nums[lo]<=nums[mid]){
                if(nums[lo]<=t && t<=nums[mid]){
                    hi=mid-1;
                }
                else lo=mid+1;
            }
            else if(nums[mid]<=nums[hi]){
                if(nums[mid]<=t && t<=nums[hi]){
                    lo=mid+1;
                }
                else hi=mid-1;
            }
        }
        return false;
        
        
    }
};