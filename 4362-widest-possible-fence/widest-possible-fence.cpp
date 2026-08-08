class Solution {
public:
    typedef long long int ll;
    int maximumWidth(vector<int>& planks) {

        int n=planks.size();
        unordered_map<ll,ll> f;
        for(int i=0;i<n;i++){
            f[planks[i]]++;
        }
        vector<pair<ll,ll>> v;
        for(auto &x:f){
            ll h=x.first;
            ll f=x.second;
            v.push_back({h,f});
        }
        ll ans=1;
        ll m=v.size();
        unordered_map<ll,ll> w;
        for(int i=0;i<m;i++){
            ll h=v[i].first;
            ll f=v[i].second;
            w[h]=f;
            ans=max(ans,f);
        }
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                ll h=v[i].first;
                ll f=v[i].second;
                if(i==j){
                    w[2*h]+=f/2;
                    ans=max(ans,w[2*h]);
                }
                else{
                    ll hh=v[j].first;
                    ll ff=v[j].second;
                    w[h+hh]+=min(f,ff);
                    ans=max(ans,w[h+hh]);
                }
                
            }
        }
        return ans;
        
    }
};