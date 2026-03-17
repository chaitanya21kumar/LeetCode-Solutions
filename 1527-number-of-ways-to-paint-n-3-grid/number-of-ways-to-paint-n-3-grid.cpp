class Solution {
public:
    vector<string> v={"RGY","RYG","RYR","RGR","GYR","GRY","GRG","GYG","YGR","YRG","YRY","YGY"};
    #define M 1000000007
    int dp[5010][15];
    int f(int n,int i){
        if(n==0) return 1;
        if(dp[n][i]!=-1) return dp[n][i];
        string last=v[i];
        int ans=0;
        for(int j=0;j<12;j++){
            string curr=v[j];
            if(curr==last) continue;
            bool possible=true;
            for(int k=0;k<3;k++){
                if(curr[k]==last[k]){
                    possible=false;
                    break;
                }
            }
            if(possible){
                ans=(ans+f(n-1,j))%M;
            }
        }
        return dp[n][i]=ans;
    }
    int numOfWays(int n) {

        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<12;i++){
            ans=(ans+f(n-1,i))%M;
        }
        return ans;
        
    }
};