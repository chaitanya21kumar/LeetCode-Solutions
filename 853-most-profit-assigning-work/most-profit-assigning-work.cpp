class Solution {
public:
    typedef long long int ll;
    const static bool comp(const vector<int> &a,const vector<int> &b){
        if(a[0]!=b[0]){
            return a[0]>b[0];
        }
        return a[1]>b[1];
    }
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {

        ll n=d.size();
        ll m=w.size();

        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({p[i],d[i]});
        }
        sort(v.begin(),v.end(),comp);
        ll ans=0;
        sort(w.begin(),w.end(),greater<int>());
        ll j=0;
        for(ll i=0;i<n;i++){
            ll pi=v[i][0],di=v[i][1];
            while(j<m && w[j]>=di){
                ans+=pi;
                j++;
            }
        }
        return ans;

    }
};