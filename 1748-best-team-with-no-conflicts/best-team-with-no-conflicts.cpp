class Solution {
public:
    int f(int ci,int pi,int n,vector<vector<int>> &dp,vector<vector<int>> &v){

        if(ci==n){
            return 0;
        }
        if(dp[ci][pi+1]!=-1) return dp[ci][pi+1];
        int skip=f(ci+1,pi,n,dp,v);
        int pick=0;
        if(pi==-1 || v[ci][1]>=v[pi][1]){
            pick=v[ci][1]+f(ci+1,ci,n,dp,v);
        }
        return dp[ci][pi+1]=max(skip,pick);

    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        int n=ages.size();
        vector<vector<int>> dp(n+10,vector<int> (n+10,-1));
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        return f(0,-1,n,dp,v);
        
    }
};