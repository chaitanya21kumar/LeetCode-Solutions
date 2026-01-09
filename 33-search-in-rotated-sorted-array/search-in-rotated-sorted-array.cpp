class Solution {
public:
    int search(vector<int>& nums, int t) {

        int n=nums.size();
        int lo=0,hi=n-1;

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(nums[mid]==t) return mid;
            else if(nums[lo]<=nums[mid]){
                if(t>=nums[lo] && t<=nums[mid]) hi=mid-1;
                else lo=mid+1;
            }
            else if(nums[mid]<=nums[hi]){
                if(t>=nums[mid] && t<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;

        
        
    }
};