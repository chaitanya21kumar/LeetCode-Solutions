class Solution {
public:
    int f(vector<int> &v){
        int mx=v[0]+v[1];
        int pl1mx=v[0];
        for(int i=1;i<v.size();i++){
            int cmx=v[i]+pl1mx;
            mx=max(mx,cmx);
            pl1mx=max(v[i],pl1mx+v[i]);
        }
        return mx;
    }
    int maxScore(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        int mx=INT_MIN;

        for(int i=0;i<m;i++){
            mx=max(mx,f(grid[i]));
        }

        vector<int> col(m);
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                col[i]=grid[i][j];
            }
            mx=max(mx,f(col));
        }

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                mx=max(mx,grid[i][j]);
            }
        }

        return mx;

    }
};