class Solution {
public:
    int f(int i,int j,string &s1,string &s2,int m,int n,vector<vector<int>> &dp){
        if(i==m){
            int rs=0;
            for(int k=j;k<n;k++){
                rs+=s2[k];
            }
            return rs;
        }
        if(j==n){
            int rs=0;
            for(int k=i;k<m;k++){
                rs+=s1[k];
            }
            return rs;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        int skip=0;
        int pick=0;
        if(s1[i]==s2[j]){
            skip=f(i+1,j+1,s1,s2,m,n,dp);
            ans=skip;
        }
        else{
            int p1=s1[i]+f(i+1,j,s1,s2,m,n,dp);
            int p2=s2[j]+f(i,j+1,s1,s2,m,n,dp);
            pick=min(p1,p2);
            ans=pick;
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m+10,vector<int>(n+10,-1));
        return f(0,0,s1,s2,m,n,dp);

    }
};