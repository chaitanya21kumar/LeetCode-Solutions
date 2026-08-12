class Solution {
public:
    int f(int i,int j,int n1,int n2,vector<vector<int>> &dp,string &w1,string &w2){
        if(i==n1 && j==n2) return 0;
        if(i==n1) return n2-j;
        if(j==n2) return n1-i;

        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]) dp[i][j]=f(i+1,j+1,n1,n2,dp,w1,w2);
        else{
            int ins=1+f(i,j+1,n1,n2,dp,w1,w2);
            int del=1+f(i+1,j,n1,n2,dp,w1,w2);
            int rep=1+f(i+1,j+1,n1,n2,dp,w1,w2);
            dp[i][j]=min({ins,del,rep});
        }
        
        return dp[i][j];
        
    }
    int minDistance(string word1, string word2) {

        int n1=word1.size();
        int n2=word2.size();

        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        return f(0,0,n1,n2,dp,word1,word2);
        
    }
};