class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(auto &x:dirs){
                        int ii=i+x[0],jj=j+x[1];
                        if(ii<0 || ii>=n || jj<0 || jj>=m) ans++; 
                        else if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]==0) ans++;
                    }
                }
            }
        }

        return ans;
        
    }
};