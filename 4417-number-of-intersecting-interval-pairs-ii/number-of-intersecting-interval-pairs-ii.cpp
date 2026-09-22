class Solution {
public:
    typedef long long int ll;
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        ll n=intervals.size();
        vector<ll> v(n);
        sort(intervals.begin(),intervals.end());
        for(ll i=0;i<n;i++){
            v[i]=intervals[i][0];
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            int x=intervals[i][1];
            auto it=upper_bound(v.begin()+i+1,v.end(),x);
            ans+=it-(v.begin()+i+1);
        }
        return ans;
        
    }
};