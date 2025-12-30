class Solution {
public:
    int dp[25][25];
    int f(int i,int j,int n1,int n2,string &s1,string &s2){
        if(j>=n2 && i>=n1) return 1;
        if(j>=n2 && i<n1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int fcm=0; // first char match
        if( i<n1 && (s1[i]==s2[j] || s2[j]=='.')) fcm=1;

        if(j+1<n2 && s2[j+1]=='*'){
            int take=fcm && f(i+1,j,n1,n2,s1,s2);
            int nottake=f(i,j+2,n1,n2,s1,s2);

            dp[i][j]=take || nottake;
        }
        else{
            dp[i][j]=fcm && f(i+1,j+1,n1,n2,s1,s2);
        }

        return dp[i][j];

    }
    bool isMatch(string s, string p) {

        int n1=s.size(),n2=p.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,n1,n2,s,p);
        
    }
};