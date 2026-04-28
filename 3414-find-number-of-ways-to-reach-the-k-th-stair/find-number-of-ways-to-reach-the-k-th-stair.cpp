class Solution {
public:
    unordered_map<string,int> dp;
    int f(int cs,int k,int d,int j){
        if(cs>k+1) return 0;
        string key=to_string(cs)+"_"+to_string(d)+"_"+to_string(j);
        if(dp.count(key)) return dp[key];
        int ways=0;
        if(cs==k) ways=1;
        int p1=0;
        if(d==1 && cs>0){
            p1=f(cs-1,k,0,j);
        }
        int p2=f(cs+(pow(2,j)),k,1,j+1);

        return dp[key]=ways+p1+p2;
    }
    int waysToReachStair(int k) {

        return f(1,k,1,0); // (cur,k,down,jumps)
        
    }
};