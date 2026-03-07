class Solution {
public:
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j,int m,int n,vector<vector<int>> &vis,vector<vector<char>>& grid){

        vis[i][j]=1;
        for(auto &x:dirs){
            int r=i+x[0],c=j+x[1];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1' && !vis[r][c]){
                dfs(r,c,m,n,vis,grid);
            }
        }


    }
    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,m,n,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};