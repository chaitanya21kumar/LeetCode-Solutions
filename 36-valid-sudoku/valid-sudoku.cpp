class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int r[10][10],c[10][10],b[10][10];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'0';
                int box=(i/3)*3+(j/3);
                if(r[i][num] || c[j][num] || b[box][num]) return false;
                r[i][num]=1;c[j][num]=1;b[box][num]=1;
            }
        }
        return true;
        
    }
};