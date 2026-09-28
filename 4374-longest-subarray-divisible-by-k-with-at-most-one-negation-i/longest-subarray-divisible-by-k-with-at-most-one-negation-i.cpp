class Solution {
public:
    typedef long long int ll;
    int longestSubarray(vector<int>& nums, int k) {

        int n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            ll s=0;
            unordered_set<ll> st;
            for(int j=i;j<n;j++){
                s+=nums[j];
                ll m1=(s%k + k)%k;
                ll m2=((2*nums[j])%k + k)%k;
                st.insert(m2);
                if(m1==0 || st.find(m1)!=st.end()){
                    ans=max(ans,(ll)j-i+1);
                }
            }
        }
        return ans;
        
    }
};