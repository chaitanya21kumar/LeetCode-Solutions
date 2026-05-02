class Solution {
public:
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& vis){

        vis[i][j]=1;
        int s=grid[i][j];
        for(auto &x:dirs){
            int r=i+x[0],c=j+x[1];
            if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0 && grid[r][c]>0){
                s+=dfs(r,c,n,m,grid,vis);
            }
        }

        return s;

    }
    int findMaxFish(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    ans=max(ans,dfs(i,j,n,m,grid,vis));
                }
            }
        }
        return ans;
        
    }
};