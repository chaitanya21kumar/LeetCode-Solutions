class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {

        int n=moves.size();
        vector<int> rs(3,0),sc(3,0);
        int d=0,ad=0;
        for(int i=0;i<n;i++){
            int p=0;
            if(i%2==0) p=1;
            else p=-1;

            int r=moves[i][0],c=moves[i][1];
            rs[r]+=p;
            sc[c]+=p;

            if(r==c) d+=p;
            if(r+c==2) ad+=p;

            if(abs(rs[r])==3 || abs(sc[c])==3 || abs(d)==3 || abs(ad)==3){
                if(p==1) return "A";
                return "B";
            }

        }
        if(n==9) return "Draw";
        return "Pending";
        
    }
};