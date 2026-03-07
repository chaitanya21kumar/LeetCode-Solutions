class Solution {
public:
    typedef long long int ll;
    long long countBadPairs(vector<int>& nums) {

        ll n=nums.size();
        vector<ll> v;
        unordered_map<ll,ll> m;
        for(int i=0;i<n;i++){
            v.push_back(nums[i]-i);
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=(i-m[v[i]]);
            m[v[i]]++;
        }
        return ans;
        
    }
};