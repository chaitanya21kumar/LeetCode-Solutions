class Solution {
public:
    typedef long long int ll;
    long long countBadPairs(vector<int>& nums) {

        ll n=nums.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=nums[i]-i;
        }
        ll ans=0;
        unordered_map<ll,ll> m;
        for(int i=0;i<n;i++){
            ans+=(i-m[v[i]]);
            m[v[i]]++;
        }
        return ans;
        
    }
};