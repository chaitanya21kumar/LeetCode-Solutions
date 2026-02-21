class Solution {
public:
    typedef long long int ll;
    bool possible(vector<int>& d, vector<int>& r,ll t){
        ll t1=t-t/r[0];
        ll t2=t-t/r[1];
        if(d[0]>t1 || d[1]>t2) return false;
        if(d[0]+d[1]<=t-t/(lcm(r[0],r[1]))) return true;
        return false;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {

        ll lo=1,hi=1e12;
        ll ans=hi;
        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            if(possible(d,r,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};