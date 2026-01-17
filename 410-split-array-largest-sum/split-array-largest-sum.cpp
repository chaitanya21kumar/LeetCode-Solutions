class Solution {
public:
    typedef long long int ll;
    bool possible(ll mid,vector<int>& nums,int k){
        ll sum=0,nos=1; // nos number of subarr
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid) sum+=nums[i];
            else{
                sum=nums[i];
                nos++;
            }
            if(nos>k) return false;
        }
        return true;
        
    }
    int splitArray(vector<int>& nums, int k) {

        ll n=nums.size();
        ll lo=0;
        ll hi=0;
        ll ans=INT_MAX;
        for(int i=0;i<n;i++){
            hi+=nums[i];
            lo=max(lo,(ll)nums[i]);
        }

        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            if(possible(mid,nums,k)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;

    }
};