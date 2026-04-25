class Solution {
public:
    typedef long long int ll;
    long long maxPoints(vector<vector<int>>& points) {

        ll m=points.size();
        ll n=points[0].size();

        vector<ll> p(n),c(n);

        for(int i=0;i<n;i++){
            p[i]=points[0][i];
        }

        ll ans=INT_MIN;

        for(int i=1;i<m;i++){
            vector<ll> l(n),r(n);
            l[0]=p[0];
            for(int j=1;j<n;j++){
                l[j]=max(p[j],l[j-1]-1);
            }
            r[n-1]=p[n-1];
            for(int j=n-2;j>=0;j--){
                r[j]=max(p[j],r[j+1]-1);
            }
            for(int j=0;j<n;j++){
                c[j]=points[i][j]+max(l[j],r[j]);
            }
            p=c;
        }

        return *max_element(p.begin(),p.end());


        
    }
};