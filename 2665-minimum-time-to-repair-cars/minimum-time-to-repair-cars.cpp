class Solution {
public:
    typedef long long int ll;
    bool f(vector<int>& ranks,ll mid,ll c){
        ll ct=0;
        for(int i=0;i<ranks.size();i++){
            ct+=sqrt(mid/ranks[i]);
        }
        if(ct>=c) return true;
        return false;
    }
    long long repairCars(vector<int>& ranks, int c) {

        ll n=ranks.size();

        ll lo=0;
        ll hi=1e14;
        ll ans=hi;

        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            if(f(ranks,mid,c)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
        
    }
};