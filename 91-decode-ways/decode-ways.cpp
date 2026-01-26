class Solution {
public:
    int dp[110];
    int f(int i,int n,string &s){
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        int num=0;
        for(int j=i;j<n;j++){
            num=num*10 + (s[j]-'0');
            if(num>26) break;
            ans+=f(j+1,n,s);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        return f(0,n,s);
    }
};