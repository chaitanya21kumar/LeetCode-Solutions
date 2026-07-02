class Solution {
public:
    int maxDistance(string moves) {

        int n=moves.size();
        int cu=0,cd=0,cr=0,cl=0,cds=0;
        for(int i=0;i<n;i++){
            char ch=moves[i];
            if(ch=='U') cu++;
            else if(ch=='R') cr++;
            else if(ch=='D') cd++;
            else if(ch=='L') cl++;
            else cds++;
        }
        return abs(abs(cu)-abs(cd))+abs(abs(cr)-abs(cl))+cds;
        
    }
};