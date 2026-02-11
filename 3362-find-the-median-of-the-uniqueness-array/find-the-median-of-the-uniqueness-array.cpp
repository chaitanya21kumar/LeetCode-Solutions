class Solution {
public:
    typedef long long int ll;
    ll f(vector<int>& nums,ll n,ll mid){
        ll l=0,r=0,cd=0,ans=0;
        unordered_map<ll,ll> m;
        while(r<n){
            if(m[nums[r]]==0) cd++;
            m[nums[r]]++;
            while(cd>mid){
                m[nums[l]]--;
                if(m[nums[l]]==0) cd--;
                l++;
            }
            if(cd<=mid) ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int medianOfUniquenessArray(vector<int>& nums) {

        ll n=nums.size();
        unordered_set<ll> s;
        for(auto &x:nums) s.insert(x);
        ll lo=1,hi=s.size();
        ll tnos=(n*(n+1))/2;
        ll r=(tnos+1)/2; // rank, exactly half of subarr must be less than or equal to this for this to be the median 
        ll ans=hi;
        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            ll c=f(nums,n,mid);
            if(c>=r){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;

    }
};