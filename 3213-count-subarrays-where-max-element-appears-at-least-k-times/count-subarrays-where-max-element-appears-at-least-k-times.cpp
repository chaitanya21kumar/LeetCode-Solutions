class Solution {
public:
    typedef long long int ll;
    long long countSubarrays(vector<int>& nums, int k) {

        int n=nums.size();
        ll l=0,r=0,cmx=0,ans=0;
        int mx=nums[0];
        for(int i=0;i<n;i++) mx=max(mx,nums[i]);

        while(r<n){
            if(nums[r]==mx) cmx++;
            while(l<=r && cmx>=k){
                ans+=(n-r);
                if(nums[l]==mx){
                    cmx--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};