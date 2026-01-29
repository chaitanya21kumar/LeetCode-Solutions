class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(k>0 && i<n){
            if(nums[i]<0){
                nums[i]=-1*nums[i];
                k--;
            }
            i++;
        }
        int mxs=0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mxs+=nums[i];
            mn=min(mn,nums[i]);
        }
        if(k%2!=0) mxs-=2*mn;
        return mxs;


        
        
    }
};