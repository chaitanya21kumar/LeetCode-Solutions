class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,int &cs,int m,int n){
        vis[i][j]=1;
        cs++;
        for(auto &x:dir){
            int ii=x[0];
            int jj=x[1];
            int nr=i+ii;
            int nc=j+jj;
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1) dfs(nr,nc,vis,grid,cs,m,n);
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cs=0;
                if(!vis[i][j] && grid[i][j]==1) dfs(i,j,vis,grid,cs,m,n);
                ans=max(ans,cs);
            }
        }
        return ans;


        
    }
};