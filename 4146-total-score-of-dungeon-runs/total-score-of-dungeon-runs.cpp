class Solution {
public:
    typedef long long int ll;
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {

        ll n=damage.size();
        ll ans=0;
        vector<ll> p(n,0);
        p[0]=damage[0];
        for(int i=1;i<n;i++){
            p[i]=p[i-1]+damage[i];
        }
        for(int i=0;i<n;i++){
            ll chp=hp-p[i]; // current horse power
            if(chp>=requirement[i]) ans++;
            ll debt=requirement[i]-chp;
            if(i>0){
                auto it=lower_bound(p.begin(),p.begin()+i,debt);
                ll skips=distance(it,p.begin()+i);
                ans+=skips;
            }
        }
        return ans;

        
    }
};