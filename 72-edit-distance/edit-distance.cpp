class Solution {
public:
    int dp[550][550];
    int f(int i,int j,int n1,int n2,string &s1,string &s2){
        if(i==n1 && j<n2) return n2-j;
        if(j==n2 && i<n1) return n1-i;
        if(j==n2 && i==n1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int rem=INT_MAX,rep=INT_MAX,ins=INT_MAX;
        if(s1[i]==s2[j]){
            rem=f(i+1,j+1,n1,n2,s1,s2);
        }
        else{
            rem=1+f(i+1,j,n1,n2,s1,s2);
            rep=1+f(i+1,j+1,n1,n2,s1,s2);
            ins=1+f(i,j+1,n1,n2,s1,s2);
        }

        return dp[i][j]=min({rem,rep,ins});

    }
    int minDistance(string word1, string word2) {

        int n1=word1.size(),n2=word2.size();
        memset(dp,-1,sizeof(dp));

        return f(0,0,n1,n2,word1,word2);

        
    }
};