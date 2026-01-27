class Solution {
public:
    int dp[51][51][51][51];
    int f(int r1,int c1,int r2,int c2,int n,vector<vector<int>>& grid){
        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;  
        if(r1==n-1 && c1==n-1){
            if(grid[r1][c1]==1) return 1;
            return 0;
        }
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        int ans=0;
        if(r1==r2 && c1==c2){
            if(grid[r1][c1]==1) ans+=1;
        }
        else{
            if(grid[r1][c1]==1) ans+=1;
            if(grid[r2][c2]==1) ans+=1;
        }
        int p1=f(r1,c1+1,r2,c2+1,n,grid);
        int p2=f(r1+1,c1,r2+1,c2,n,grid);
        int p3=f(r1,c1+1,r2+1,c2,n,grid);
        int p4=f(r1+1,c1,r2,c2+1,n,grid);
        int mx=max({p1,p2,p3,p4});
        if(mx==INT_MIN){
            return dp[r1][c1][r2][c2]=INT_MIN;
        }
        return dp[r1][c1][r2][c2]=ans+mx;
       
    }
    int cherryPickup(vector<vector<int>>& grid) {

        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,0,0,n,grid);
        if(ans==INT_MIN) return 0;
        return ans;
        
    }
};