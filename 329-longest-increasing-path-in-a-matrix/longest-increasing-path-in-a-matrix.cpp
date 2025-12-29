class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int res=1;
    int dp[250][250];
    int dfs(int i,int j,int m,int n,vector<vector<int>>& matrix,int t){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int r=i+dr[k];
            int c=j+dc[k];
            int len=1;
            if(r>=0 && r<m && c>=0 && c<n && matrix[r][c]>matrix[i][j]){
                len=1+dfs(r,c,m,n,matrix,t+1);
            }
            ans=max(ans,len);
        }

        return dp[i][j]=ans;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m=matrix.size(),n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp=1;
                ans=max(ans,dfs(i,j,m,n,matrix,temp));
            }
        }

        return ans;
        
    }
};