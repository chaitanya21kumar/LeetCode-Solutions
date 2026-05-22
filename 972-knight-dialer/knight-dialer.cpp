class Solution {
public:
    #define M 1000000007
    int dp[5][4][50010];
    int f(int i,int j,int r,int c,vector<vector<int>> &dirs,int n){

        if(n==1) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        int ans=0;
        for(auto &x:dirs){
            int ri=i+x[0],ci=j+x[1];
            if(ri>=0 && ri<=3 && ci>=0 && ci<=2){
                if( (ri==3 && ci==0) || (ri==3 && ci==2) ) continue;
                else ans=(ans+f(ri,ci,r,c,dirs,n-1))%M;
            }
        }
        return dp[i][j][n]=ans;

    }
    int knightDialer(int n) {

        vector<vector<int>> dirs={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        int r=4,c=3;
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if( (i==3 && j==0) || (i==3 && j==2) ) continue;
                else ans=(ans+f(i,j,r,c,dirs,n))%M;
            }
        }
        return ans;

    }
};