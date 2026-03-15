class Solution {
public:
    int dp[210][210][3];
    #define M 1000000007
    int f(int z,int o,bool lw1,int l){
        if(z==0 && o==0) return 1;
        if(dp[z][o][lw1]!=-1) return dp[z][o][lw1];
        int ans=0;
        if(lw1){
            for(int i=1;i<=min(z,l);i++){
                ans=(ans+f(z-i,o,false,l))%M;
            }
        }
        else{
            for(int i=1;i<=min(o,l);i++){
                ans=(ans+f(z,o-i,true,l))%M;
            }
        }
        return dp[z][o][lw1]=ans;

    }
    int numberOfStableArrays(int z, int o, int l) {

        memset(dp,-1,sizeof(dp));
        int sw0=f(z,o,true,l)%M;
        int sw1=f(z,o,false,l)%M;
        return (sw0+sw1)%M;
        
    }
};