class Solution {
public:
    typedef long long int ll;
    bool possible(ll mid,ll h,vector<int> &v){
        ll th=0;
        for(ll i=0;i<v.size();i++){
            ll time=0;
            ll x=1;
            while(time<mid){
                if(time+v[i]*x <=mid){
                    time+=v[i]*x;
                    x++;
                    th++;
                }
                else break;
                if(th>=h) return true;
            }
        }
        if(th>=h) return true;
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        ll lo=1;
        ll hi=1e18;
        ll ans=1e18;
        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            if(possible(mid,mountainHeight,workerTimes)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};