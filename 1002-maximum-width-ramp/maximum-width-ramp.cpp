class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n=nums.size();
        vector<int> rm(n);
        rm[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rm[i]=max(rm[i+1],nums[i]);
        }
        int i=0,j=0,ramp=0;
        while(j<n){
            while(i<j && nums[i]>rm[j]){
                i++;
            }
            ramp=max(ramp,j-i);
            j++;
        }
        return ramp;
        
    }
};