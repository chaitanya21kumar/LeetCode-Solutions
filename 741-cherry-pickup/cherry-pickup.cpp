class Solution {
public:
    int dp[51][51][51][51];
    typedef long long int ll;
    int f(int r1,int c1,int r2,int c2,int n,vector<vector<int>>& grid){
        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r1==n-1 && c1==n-1) return grid[r1][c1];
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        long long int ans=0;
        if(r1==r2 && c1==c2) ans+=grid[r1][c1];
        else ans+=grid[r1][c1]+grid[r2][c2];

        int p1=f(r1,c1+1,r2,c2+1,n,grid);
        int p2=f(r1,c1+1,r2+1,c2,n,grid);
        int p3=f(r1+1,c1,r2,c2+1,n,grid);
        int p4=f(r1+1,c1,r2+1,c2,n,grid);
        ans+=max({p1,p2,p3,p4});
        return dp[r1][c1][r2][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {

        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        return max(0,f(0,0,0,0,n,grid));
        
    }
};