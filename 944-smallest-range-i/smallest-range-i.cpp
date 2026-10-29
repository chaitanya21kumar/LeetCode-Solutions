class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {

        int n=nums.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        return max(0,mx-mn-2*k);
        
    }
};