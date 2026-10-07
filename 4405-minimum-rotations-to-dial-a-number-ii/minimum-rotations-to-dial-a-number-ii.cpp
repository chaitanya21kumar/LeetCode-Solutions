class Solution {
public:
    typedef long long int ll;
    ll f(char a,char b){
        ll n1=a-'0';
        ll n2=b-'0';
        ll d=abs(n1-n2);
        ll fd=min(d,abs(10-d));
        return fd;
    }
    int minRotations(int n, string s) {

        ll b=f('0',s[0]);
        for(int i=1;i<n;i++){
            b+=f(s[i-1],s[i]);
        }
        ll ans=b;
        for(int k=0;k<n;k++){
            ll c=b;
            if(k==0){
                c-=f('0',s[k]);
                c+=f('0',s[n-1]);
            }
            else{
                c-=f(s[k-1],s[k]);
                c+=f(s[k-1],s[n-1]);
            }
            ans=min(ans,c);
        }
        return ans;

    }
};