class Solution {
public:
    typedef long long int ll;
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {

        ll n=monsters.size();
        ll m=boosts.size();

        vector<ll> d(n+1,0);
        for(auto &x:boosts){
            ll l=x[0];
            ll r=x[1];
            ll v=x[2];
            d[l]+=v;
            d[r+1]-=v;
        }
        ll bonus=0;
        ll ans=0;
        ll loss=0;
        for(int i=0;i<n;i++){
            bonus+=d[i];
            if(bonus<monsters[i]){
                ll need=loss+monsters[i]-bonus;
                ans=max(ans,need);
            }
            loss+=monsters[i];
        }
        return ans;

    }
};