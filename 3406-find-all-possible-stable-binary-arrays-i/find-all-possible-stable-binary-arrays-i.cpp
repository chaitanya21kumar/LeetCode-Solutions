class Solution {
public:
    #define M 1000000007
    int dp[210][210][2];
    int f(int cz,int co,bool lone,int l){
        if(cz==0 && co==0) return 1;
        if(dp[cz][co][lone]!=-1) return dp[cz][co][lone];
        int ans=0;
        if(lone==true){
            for(int i=1;i<=min(cz,l);i++){
                ans=(ans+f(cz-i,co,false,l))%M;
            }
        }
        else{
            for(int i=1;i<=min(l,co);i++){
                ans=(ans+f(cz,co-i,true,l))%M;
            }
        }
        return dp[cz][co][lone]=ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {

        memset(dp,-1,sizeof(dp));
        int swone=f(zero,one,false,limit)%M;
        int swzero=f(zero,one,true,limit)%M;
        return (swone+swzero)%M;

        
    }
};