class Solution {
public:
    int dp[150][150][250];
    int f(int i,int j,int k,int n1,int n2,int n3,string &s1,string &s2,string &s3){

        if(i==n1 && j==n2 && k==n3) return true;
        if(k>=n3) return false;
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int ans1=0,ans2=0;

        if(s1[i]==s3[k]) ans1=f(i+1,j,k+1,n1,n2,n3,s1,s2,s3);
        if(s2[j]==s3[k]) ans2=f(i,j+1,k+1,n1,n2,n3,s1,s2,s3);

        int ans=-1;
        if(ans1==1 || ans2==1) ans=1;
        else ans=0;

        return dp[i][j][k]=ans;



    }
    bool isInterleave(string s1, string s2, string s3) {

        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        memset(dp,-1,sizeof(dp));
        if((n1+n2)!=n3) return false;
        return f(0,0,0,n1,n2,n3,s1,s2,s3);
        
    }
};