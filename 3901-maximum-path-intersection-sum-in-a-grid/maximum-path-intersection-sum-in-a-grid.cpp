class Solution {
public:
    int f(vector<int> &v){
        int n=v.size();

        int mx=v[0]+v[1];
        int pvl1mx=v[0];
        for(int i=1;i<n;i++){
            int cmx=v[i]+pvl1mx;
            mx=max(mx,cmx);
            pvl1mx=max(v[i],pvl1mx+v[i]);
        }
        return mx;
    }
    int maxScore(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        int mx=INT_MIN;

        for(int i=0;i<m;i++){
            int x=f(grid[i]);
            mx=max(mx,x);
        }

        vector<int> col(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                col[j]=grid[j][i];
            }
            int x=f(col);
            mx=max(mx,x);
        }

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                mx=max(mx,grid[i][j]);
            }
        }

        return mx;
        
    }
};