class Solution {
public:
    typedef long long int ll;
    int f(int i,int n,int num,vector<vector<int>> &dp,vector<ll> &ps){

        if(num==0) return 0;
        if(i>=n) return 1e9;
        if(dp[i][num]!=-1) return dp[i][num];
        int pick=1e9,notpick=1e9;
        if(num>=ps[i]){
            pick=1+f(i,n,num-ps[i],dp,ps);
        }
        notpick=f(i+1,n,num,dp,ps);
        return dp[i][num]=min(pick,notpick);

    }
    int numSquares(int n) {
        
        vector<ll> ps;
        for(int i=1;i*i<=n;i++){
            ps.push_back(i*i);
        }
        vector<vector<int>> dp((int)ps.size()+10,vector<int> (n+10,-1));
        return f(0,ps.size(),n,dp,ps);

    }
};