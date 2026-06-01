class Solution {
public:
    typedef long long int ll;
    bool possible(ll mid,vector<int>& nums,ll n,ll k,vector<ll> &p){
        ll i=0,j=mid-1;

        while(j<n){
            ll tidx=(i+j)/2;
            ll opsl=0,opsr=0;
            opsl=abs((tidx-i)*nums[tidx] - ( (tidx-1>=0?p[tidx-1]:0)-(i-1>=0?p[i-1]:0)));
            opsr=abs((j-tidx)*nums[tidx] - (p[j]-p[tidx]) );

            if(opsl+opsr<=k) return true;
            i++;
            j++;
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {

        ll n=nums.size();
        sort(nums.begin(),nums.end());
        ll lo=1,hi=n;
        ll ans=-1;
        vector<ll> p(n);
        p[0]=nums[0];
        for(int i=1;i<n;i++){
            p[i]=nums[i]+p[i-1];
        }
        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            if(possible(mid,nums,n,k,p)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;

    }
};