class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {

        int n=nums.size();
        vector<int> pm(n); // prefix max array
        pm[0]=nums[0];

        for(int i=1;i<n;i++){
            pm[i]=max(pm[i-1],nums[i]);
        }

        int mxs=INT_MIN; // max sum

        for(int j=k;j<n;j++){
            int i=j-k;
            int x=pm[i]+nums[j];
            mxs=max(mxs,x);
        }

        return mxs;

    }
};