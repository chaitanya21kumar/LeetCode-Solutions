class Solution {
public:
    typedef long long int ll;
    long long countGood(vector<int>& nums, int k) {

        ll n=nums.size();
        ll ans=0,p=0;
        ll l=0,r=0;
        unordered_map<int,int> m;
        while(r<n){
            p+=m[nums[r]];
            m[nums[r]]++;
            while(p>=k){
                ans+=n-r;
                p-=(m[nums[l]]-1);
                m[nums[l]]--;
                l++;
            }
            r++;
        }
        return ans;
        
    }
};