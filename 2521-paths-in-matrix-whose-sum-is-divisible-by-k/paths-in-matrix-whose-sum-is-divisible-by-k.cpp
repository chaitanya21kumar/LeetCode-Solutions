class Solution {
public:
    #define M 1000000007
    typedef long long int ll;
    int f(int i,int j,int s,int m,int n,int k,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        s+=grid[i][j];
        s%=k;
        if(i==m-1 && j==n-1){
            if(s%k==0) return 1;
            return 0;
        }
        if(dp[i][j][s]!=-1) return dp[i][j][s];
        int r=0,d=0;
        if(j+1<n){
            r=f(i,j+1,s,m,n,k,grid,dp);
        }
        if(i+1<m){
            d=f(i+1,j,s,m,n,k,grid,dp);
        }
        return dp[i][j][s]=(r+d)%M;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m+10,vector<vector<int>> (n+10,vector<int> (k+10,-1)));
        return f(0,0,0,m,n,k,grid,dp);

        
    }
};