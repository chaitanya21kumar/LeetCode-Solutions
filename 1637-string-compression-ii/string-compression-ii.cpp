int dp[101][101][27][101];
class Solution {
public:
    int f(int i,int n ,int k,int pc,int fpc,string &s){
        if(k<0) return INT_MAX;
        if(i>=n) return 0;
        if(dp[i][k][pc][fpc]!=-1) return dp[i][k][pc][fpc];

        int skip=f(i+1,n,k-1,pc,fpc,s);
        int keep=INT_MAX;
        if(pc!=s[i]-'a'){
            keep=1+f(i+1,n,k,s[i]-'a',1,s);
        }
        else{
            if(fpc==1 || fpc==9 || fpc==99){
                int oma=1;
                keep=oma+f(i+1,n,k,pc,fpc+1,s);
            }
            else{
                keep=f(i+1,n,k,pc,fpc+1,s);
            }
        }
        return dp[i][k][pc][fpc]=min(keep,skip);

    }
    int getLengthOfOptimalCompression(string s, int k) {

        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n,k,26,0,s); // {i,n,k,previous char,freq of prev char}
        
    }
};