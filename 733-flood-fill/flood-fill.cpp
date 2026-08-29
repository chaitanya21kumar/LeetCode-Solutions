class Solution {
public:
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<int>> &v,vector<vector<int>> &image,int cr,int cc,int m,int n,int color){
        int ic=image[cr][cc];
        v[cr][cc]=color;
        for(auto &x:dirs){
            int nr=cr+x[0];
            int nc=cc+x[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && v[nr][nc]==ic && v[nr][nc]!=color){
                dfs(v,image,nr,nc,m,n,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> v=image;
        dfs(v,image,sr,sc,m,n,color);
        return v;
        
    }
};