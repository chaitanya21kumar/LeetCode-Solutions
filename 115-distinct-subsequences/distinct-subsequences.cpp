class Solution {
public:
    int dp[1050][1050];
    int f(int i,int j,int n1,int n2,string &s1,string &s2){
        if(j==n2) return 1;
        if(i==n1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int way1=0,way2=0;

        if(s1[i]==s2[j]){
            way1=f(i+1,j+1,n1,n2,s1,s2);
            way2=f(i+1,j,n1,n2,s1,s2);
        }
        else{
            way1=f(i+1,j,n1,n2,s1,s2);
        }

        return dp[i][j]=way1+way2;
        
    }
    int numDistinct(string s, string t) {

        int n1=s.size(),n2=t.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,n1,n2,s,t);
        
    }
};