class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    int dfs(int i,int j,int k,int ws,int n,int m,vector<vector<char>>& board,string &word,vector<vector<int>> &vis){
        vis[i][j]=1;
        if(k==ws) return true;
        

        for(int l=0;l<4;l++){
            int r=i+dr[l];
            int c=j+dc[l];
            if(r>=0 && r<n && c>=0 && c<m && board[r][c]==word[k] && !vis[r][c]){
                if(dfs(r,c,k+1,ws,n,m,board,word,vis)) return true;
            }
        }
        vis[i][j]=0;

        return false;


    }
    bool exist(vector<vector<char>>& board, string word) {

        int n=board.size();
        int m=board[0].size();
        int ws=word.size(); // word size
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>> vis(n,vector<int> (m,0));
                if(board[i][j]==word[0]){
                    if(dfs(i,j,1,ws,n,m,board,word,vis)) return true;
                }
            }
        }

        return false;

        
    }
};