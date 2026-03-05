class Solution {
public:
    typedef long long int ll;
    #define M 1000000007
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        ll n=s.size();
        vector<ll> num(n);
        vector<ll> p(n);
        vector<ll> power(n+1);
        vector<ll> c(n);
        vector<int> ans(queries.size());
        power[0]=1;

        ll fd=s[0]-'0'; // first digit
        p[0]=fd;
        if(fd==0){
            c[0]=0;
            num[0]=0;
        }
        else{
            c[0]=1;
            num[0]=fd;
        }

        for(int i=1;i<=n;i++){
            power[i]=(power[i-1]*10)%M;
        }

        for(int i=1;i<n;i++){
            int d=s[i]-'0';
            if(d==0){
                p[i]=p[i-1];
                c[i]=c[i-1];
                num[i]=num[i-1];
            }
            else{
                p[i]=p[i-1]+d;
                c[i]=c[i-1]+1;
                num[i]=(num[i-1]*10 + d)%M;
            }
        }

        for(int i=0;i<queries.size();i++){
            ll l=queries[i][0],r=queries[i][1];
            ll sum=0;
            ll val=0;
            ll len=0;
            if(l==0){
                sum=p[r];
                len=c[r];
                val=num[r];
            }
            else{
                sum=p[r]-p[l-1];
                len=c[r]-c[l-1];
                val= ( num[r] - (num[l-1]*power[len])%M + M ) %M; 
            }
            ll ansi=(val%M)*(sum%M)%M;
            ans[i]=ansi;
        }

        return ans;


        
    }
};