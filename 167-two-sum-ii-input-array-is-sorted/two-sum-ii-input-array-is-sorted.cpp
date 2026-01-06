class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {

        int n=nums.size();
        int l=0,r=n-1;
        int s=nums[l]+nums[r];
        
        while(s!=t){
            if(s<t) l++;
            else if(s>t) r--;
            s=nums[l]+nums[r];
        }
        return {l+1,r+1};
        
    }
};