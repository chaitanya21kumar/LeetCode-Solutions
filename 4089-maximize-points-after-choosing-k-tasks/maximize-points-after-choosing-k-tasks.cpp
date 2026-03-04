class Solution {
public:
    typedef long long int ll;
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {

        int n=technique1.size();
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++){
            int diff=technique1[i]-technique2[i];
            v.push_back({diff,i});
        }
        sort(v.rbegin(),v.rend());
        ll ans=0;
        for(int i=0;i<n;i++){
            int idx=v[i].second;
            if(i<k) ans+=technique1[idx];
            else{
                ans+=max(technique1[idx],technique2[idx]);
            }
        }
        return ans;
        
    }
};