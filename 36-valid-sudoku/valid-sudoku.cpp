class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> s;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int val=board[i][j];
                string r=to_string(val)+" appears at row "+to_string(i);
                string c=to_string(val)+" appears at col "+to_string(j);
                string b=to_string(val)+" appears at row "+to_string(i/3)+"and col "+to_string(j/3);
                if(s.find(r)!=s.end() || s.find(c)!=s.end() || s.find(b)!=s.end()) return false;
                s.insert(r);s.insert(c);s.insert(b);
            }
        }
        return true;
        
    }
};