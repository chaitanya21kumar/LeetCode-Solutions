class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>>& grid){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(i>=m || j>=n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int p1=f(i+1,j,m,n,dp,grid);
        int p2=f(i,j+1,m,n,dp,grid);
        return dp[i][j]=grid[i][j] + min(p1,p2);
    }
    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+10,vector<int> (n+10,-1));
        return f(0,0,m,n,dp,grid);

    }
};