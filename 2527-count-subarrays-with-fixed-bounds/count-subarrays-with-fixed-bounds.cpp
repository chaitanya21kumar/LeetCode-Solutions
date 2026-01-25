class Solution {
public:
    typedef long long int ll;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int n=nums.size();
        int mnki=-1,mxki=-1,ci=-1;
        ll ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK) ci=i;
            if(nums[i]==minK) mnki=i;
            if(nums[i]==maxK) mxki=i;
            if(mnki==-1 || mxki==-1) continue;
            ll temp=min(mnki,mxki)-ci;
            if(temp>0) ans+=temp;
        }
        return ans;
    }
};