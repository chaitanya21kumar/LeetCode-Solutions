class Solution {
public:
    typedef long long int ll;
    bool possible(ll mid,ll n,vector<int>& candies,ll k){
        ll c=0;
        for(int i=0;i<n;i++){
            c+=(candies[i]/mid);
        }
        if(c>=k) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        ll ans=0;
        ll n=candies.size();
        ll l=1,r=0;
        for(int i=0;i<n;i++){
            r=max(r,(ll)candies[i]);
        }
        while(l<=r){
            ll mid=(l+(r-l)/2);
            if(possible(mid,n,candies,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};