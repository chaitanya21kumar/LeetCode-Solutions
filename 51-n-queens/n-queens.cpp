class Solution {
public:
    vector<vector<string>> ans;
    vector<int> leftrow;
    vector<int> lowerdiagonal;
    vector<int> upperdiagonal;
    void f(int col,int n,vector<string> &board){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+col-row]=1;
                f(col+1,n,board);
                leftrow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+col-row]=0;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        leftrow.resize(n,0);
        lowerdiagonal.resize(2*n-1,0);
        upperdiagonal.resize(2*n-1,0);
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        f(0,n,board);

        return ans;


        
    }
};