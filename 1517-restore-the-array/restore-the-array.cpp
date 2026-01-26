class Solution {
public:
    int dp[100010];
    #define  M 1000000007
    typedef long long int ll;
    int f(int i,string &s,int k,int n){
        if(i==n) return 1;
        if(i<n && s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        ll ans=0;
        ll num=0;
        for(int j=i;j<n;j++){
            num=num*10+(s[j]-'0');
            if(num>k) break;
            if(num>=1 && num<=k){
                ans=(ans+f(j+1,s,k,n))%M;
            }
        }
        return dp[i]=(ans%M);
    }
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        return f(0,s,k,n);
    }
};