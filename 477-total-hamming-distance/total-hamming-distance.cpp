class Solution {
public:
    typedef long long int ll;
    int totalHammingDistance(vector<int>& nums) {

        ll n=nums.size();
        ll ans=0;
        for(ll i=0;i<=32;i++){
            ll c0=0,c1=0;
            for(int j=0;j<n;j++){
                ll biti=((ll)nums[j]>>i)&1;
                if(biti==0) c0++;
                else c1++;
            }
            ans+=(c0*c1);
        }
        return ans;


        

    }
};