class Solution {
public:
    #define M 1000000007
    int f(int i,int cm,int cp,int n,int mp,vector<int>& group,vector<int>& profit,vector<vector<vector<int>>> &dp){
        if(i==group.size()){
            if(cp>=mp) return 1;
            return 0;
        }
        if(dp[i][cm][cp]!=-1) return dp[i][cm][cp];
        int skip=f(i+1,cm,cp,n,mp,group,profit,dp);
        int pick=0;
        if(cm+group[i]<=n){
            int np=min(mp,cp+profit[i]);
            pick=f(i+1,cm+group[i],np,n,mp,group,profit,dp);
        }
        return dp[i][cm][cp]=(skip+pick)%M;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        int gs=group.size();
        vector<vector<vector<int>>> dp(101,vector<vector<int>> (101,vector<int>(101,-1)));
        return f(0,0,0,n,minProfit,group,profit,dp); // {index,curr members,curr profit,n,min profit,group,profit}
        
    }
};