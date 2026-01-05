class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int p=1;
        int c0=0;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c0++;
                idx=i;
            }
            else p*=nums[i];
        }

        if(c0>1) return ans;
        if(c0==1){
            ans[idx]=p;
            return ans;
        }
        for(int i=0;i<n;i++){
            ans[i]=p/nums[i];
        }
        return ans;



    }
};