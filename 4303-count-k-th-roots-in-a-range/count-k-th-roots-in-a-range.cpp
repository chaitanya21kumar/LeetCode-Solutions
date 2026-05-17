class Solution {
public:
    typedef long long int ll;
    bool poss(ll mid,ll n,ll k){
        if(mid==0) return true;
        if(mid==1) return mid<=n;
        ll ans=1;
        for(int i=1;i<=k;i++){
            ans*=mid;
            if(ans>n) return false;
        }
        return true;
    }
    int f(ll n,ll k){
        if(n<0) return 0;
        ll lo=0;
        ll hi=n;
        ll ans=0;
        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            if(poss(mid,n,k)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans+1;
    }
    int countKthRoots(int l, int r, int k) {

        return f(r,k)-f(l-1,k);
        
    }
};