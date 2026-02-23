class Solution {
public:
    typedef long long int ll;
    bool possible(ll mid,vector<int>& time, int totalTrip){
        ll x=0;
        for(int i=0;i<time.size();i++){
            x+=(mid/time[i]);
            if(x>=totalTrip) return true;
        }
        if(x>=totalTrip) return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        ll n=time.size();
        ll lo=0,hi=1e14;
        ll ans=hi;
        while(lo<=hi){
            ll mid=(lo+(hi-lo)/2);
            if(possible(mid,time,totalTrips)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
};