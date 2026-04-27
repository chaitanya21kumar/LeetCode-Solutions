class Solution {
public:
    #define M 1000000007
    int dp[100010][3][4];
    typedef long long int lli;
    int f(int i,int n,int a,int l){
        if(i==n) return 1;
        if(dp[i][a][l]!=-1) return dp[i][a][l];

        // a
        int aa=0;
        if(a<1){
            aa=f(i+1,n,a+1,0);
        }

        // l
        int ll=0;
        if(l<2){
            ll=f(i+1,n,a,l+1);
        }

        // p
        int pp=0;
        pp=f(i+1,n,a,0);

        lli ans=(1LL*aa+1LL*ll+pp)%M;

        return dp[i][a][l]=ans;

    }
    int checkRecord(int n) {

        memset(dp,-1,sizeof(dp));
        return f(0,n,0,0); // (i,A,L)
        
    }
};