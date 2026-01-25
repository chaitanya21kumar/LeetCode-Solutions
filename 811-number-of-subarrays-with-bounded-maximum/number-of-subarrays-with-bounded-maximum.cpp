class Solution {
public:
    int f(vector<int>& nums,int n,int x){
        int l=0,r=0;
        int ans=0;
        while(r<n){
            if(nums[r]<=x){
                ans+=(r-l+1);
            }
            else{
                l=r+1;
            }
            r++;
        }
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        int n=nums.size();
        return f(nums,n,right)-f(nums,n,left-1);
        
    }
};