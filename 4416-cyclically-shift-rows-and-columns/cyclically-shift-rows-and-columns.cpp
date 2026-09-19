class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rs, vector<int>& cs) {

        vector<vector<int>> v1(n,vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int nj=(j-rs[i]+n)%n;
                v1[i][nj]=grid[i][j];
            }
        }
        vector<vector<int>> v2(n,vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ni=(i-cs[j]+n)%n;
                v2[ni][j]=v1[i][j];
            }
        }
        return v2;
        
    }
};