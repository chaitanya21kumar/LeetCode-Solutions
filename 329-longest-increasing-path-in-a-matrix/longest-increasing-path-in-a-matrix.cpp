class Solution {
public:
    int dp[250][250];
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int dfs(int i,int j,int m,int n,vector<vector<int>>& matrix){

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=1;

        for(int k=0;k<4;k++){
            int r=i+dr[k];
            int c=j+dc[k];

            if(r>=0 && r<m && c>=0 && c<n && matrix[r][c]>matrix[i][j]){
                int len=1+dfs(r,c,m,n,matrix);
                ans=max(ans,len);
            }

        }

        return dp[i][j]=ans;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m=matrix.size(),n=matrix[0].size();
        int ans=1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(i,j,m,n,matrix));
            }
        }

        return ans;
        
    }
};