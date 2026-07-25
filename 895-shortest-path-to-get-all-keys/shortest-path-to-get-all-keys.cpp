class Solution {
public:
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    int shortestPathAllKeys(vector<string>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        queue<vector<int>> q;
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    q.push({i,j,0,0});
                }
                else if(grid[i][j]>='a' && grid[i][j]<='f'){
                    c++;
                }
            }
        }

        int fksd=pow(2,c)-1; // final key status decimal
        int vis[m][n][fksd+1];
        memset(vis,0,sizeof(vis));

        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int i=x[0];
            int j=x[1];
            int s=x[2];
            int cksd=x[3];

            if(cksd==fksd) return s;
            for(auto &y:dirs){
                int nr=i+y[0];
                int nc=j+y[1];

                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!='#'){
                    char ch=grid[nr][nc];

                    if(grid[nr][nc]>='A' && grid[nr][nc]<='F'){
                        if(vis[nr][nc][cksd]==0 && ((cksd>>(ch-'A'))&1)==1){
                            vis[nr][nc][cksd]=1;
                            q.push({nr,nc,s+1,cksd});
                        }
                    }
                    else if(grid[nr][nc]>='a' && grid[nr][nc]<='f'){
                        int nsd=cksd|(1<<(ch-'a'));
                        if(vis[nr][nc][nsd]==0){
                            vis[nr][nc][nsd]=1;
                            q.push({nr,nc,s+1,nsd});
                        }
                    }
                    else{
                        if(vis[nr][nc][cksd]==0){
                            vis[nr][nc][cksd]=1;
                            q.push({nr,nc,s+1,cksd});
                        }
                    }
                }
            }
        }
        return -1;

    }
};