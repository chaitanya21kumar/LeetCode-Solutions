class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        vector<vector<int>> dirs={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        vector<vector<int>> b(8,vector<int> (8,0));
        for(auto &x:queens){
            int i=x[0],j=x[1];
            b[i][j]=1;
        }
        vector<vector<int>> ans;
        int kx=king[0],ky=king[1];
        for(auto &dir:dirs){
            int x=kx,y=ky;
            while(true){
                int xi=dir[0],yi=dir[1];
                x+=xi;
                y+=yi;
                if(x<0 || x>=8 || y<0 || y>=8) break;
                if(b[x][y]==1){
                    ans.push_back({x,y});
                    break;
                }
            }
        }
        return ans;

        
    }
};