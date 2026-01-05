class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p=1,s=1,n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=p;
            p*=nums[i];
        }

        for(int i=n-1;i>=0;i--){
            ans[i]*=s;
            s*=nums[i];
        }

        return ans;
        
    }
};