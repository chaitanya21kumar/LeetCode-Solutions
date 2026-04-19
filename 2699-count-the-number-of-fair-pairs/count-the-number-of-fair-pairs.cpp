class Solution {
public:
    typedef long long int ll;
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        ll n=nums.size();
        ll ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){

            ll lidx=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            ll nl=lidx-i-1;

            ll uidx=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            ll nu=uidx-i-1;

            ans+=(nu-nl);

        }

        return ans;
        
    }
};