class Solution {
public: 
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int dfs(int i,int j,int k,int ws,int m,int n,vector<vector<char>>& board,string &word){
        if(k==ws) return true;
        char org=board[i][j];
        board[i][j]='#';

        for(int l=0;l<4;l++){
            int r=i+dr[l];
            int c=j+dc[l];
            if(r>=0 && r<m && c>=0 && c<n && board[r][c]==word[k] && board[r][c]!='#'){
                if(dfs(r,c,k+1,ws,m,n,board,word)) return true;
            }
        }

        board[i][j]=org;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int m=board.size(),n=board[0].size(),ws=word.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,1,ws,m,n,board,word)) return true;
                }
            }
        }

        return false;
        
    }
};