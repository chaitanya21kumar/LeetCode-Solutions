class Solution {
public:
    typedef long long int ll;
    bool f(ll mid,ll n,vector<int>& batteries){
        ll a=0;
        ll r=mid*n;

        for(int i=0;i<batteries.size();i++){
            a+=(min((ll)batteries[i],mid));
        }

        if(a>=r) return true;
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {

        ll s=0;
        for(int i=0;i<batteries.size();i++){
            s+=batteries[i];
        }
        ll lo=0;
        ll hi=s;
        ll ans=0;

        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            if(f(mid,n,batteries)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
        
        
    }
};