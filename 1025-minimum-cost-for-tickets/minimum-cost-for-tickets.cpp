class Solution {
public:
    int dp[500][500];
    int f(int i,int d,vector<int>& days,vector<int>& costs){
        if(i>=days.size()) return 0;
        if(dp[i][d]!=-1) return dp[i][d];
        int p1=0,p2=0,p3=0;
        if(days[i]>=d){
            p1=costs[0]+f(i+1,days[i]+1,days,costs);
            p2=costs[1]+f(i+1,days[i]+7,days,costs);
            p3=costs[2]+f(i+1,days[i]+30,days,costs);
        }
        else{
            p1=f(i+1,d,days,costs);
            p2=f(i+1,d,days,costs);
            p3=f(i+1,d,days,costs);
        }
        return dp[i][d]=min({p1,p2,p3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n=days.size();
        memset(dp,-1,sizeof(dp));
        return f(0,days[0],days,costs);
        
    }
};