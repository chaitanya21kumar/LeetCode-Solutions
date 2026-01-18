class Solution {
public:
    typedef long long int ll;
    bool possible(ll mid,vector<int> &nums,int k){
        int tops=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){
                int x=nums[i]/mid;
                if(nums[i]%mid==0) x--;
                tops+=x;
            }
            if(tops>k) return false; 
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int k) {

        int n=nums.size();
        ll l=1,r=0;
        for(int i=0;i<n;i++) r=max(r,(ll)nums[i]);
        ll ans=r;
        while(l<=r){
            ll mid=(l+(r-l)/2);
            if(possible(mid,nums,k)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans;

        
    }
};