class Solution {
public:
    typedef long long int ll;
    long long numberOfWeeks(vector<int>& milestones) {

        ll n=milestones.size();
        ll mx=0;
        ll ts=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            ts+=milestones[i];
            mx=max((ll)mx,(ll)milestones[i]);
        }
        ll rem=ts-mx;
        if(rem>=mx-1){
            ans+=ts;
        }
        else ans+=2*rem+1;
        
        return ans;

        
    }
};