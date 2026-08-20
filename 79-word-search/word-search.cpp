class Solution {
public:
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    bool f(int i,int j,int m,int n,int idx,vector<vector<char>>& board,string &word){

        if(board[i][j]!=word[idx]) return false;
        if(idx==word.size()-1) return true;
        char ch=board[i][j];
        bool ans=false;
        board[i][j]='$';
        for(auto &x:dirs){
            int ii=x[0];
            int jj=x[1];
            int r=i+ii;
            int c=j+jj;
            if(r>=0 && r<m && c>=0 && c<n && board[r][c]!='$'){
                ans=ans|f(r,c,m,n,idx+1,board,word);
            }
        }
        board[i][j]=ch;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {

        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(f(i,j,m,n,0,board,word)) return true;
                }
            }
        }
        return false;
        
    }
};