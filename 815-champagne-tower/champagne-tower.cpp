class Solution {
public:
    double f(int p,int r,int c,vector<vector<double>> &dp){

        if(r<0 || c<0 || c>r) return 0.0;
        if(dp[r][c]!=-1) return dp[r][c];
        if(r==0 && c==0) return (double)p;

        double la=f(p,r-1,c-1,dp); // left ans
        double ra=f(p,r-1,c,dp); // right ans

        if(la>1){
            la=(la-1)/2;
        }
        else la=0;
        
        if(ra>1){
            ra=(ra-1)/2;
        }
        else ra=0;

        return dp[r][c]=(la+ra);
    }
    double champagneTower(int p, int qr, int qg) {

        vector<vector<double>> dp(qr+10,vector<double> (qg+10,-1));
        double ans=f(p,qr,qg,dp);
        return min(1.0,ans);

    }
};