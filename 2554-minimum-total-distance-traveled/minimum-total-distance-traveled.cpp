class Solution {
public:
    typedef long long int ll;
    ll f(int ri,int pi,int n,int m,vector<int>& robot, vector<int>& positions,vector<vector<ll>> &dp){
        if(ri>=n) return 0;
        if(pi>=m) return 1e15;
        if(dp[ri][pi]!=-1) return dp[ri][pi];
        
        ll take=abs(robot[ri]-positions[pi])+f(ri+1,pi+1,n,m,robot,positions,dp);
        ll skip=f(ri,pi+1,n,m,robot,positions,dp);

        return dp[ri][pi]=min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        ll n=robot.size(),m=factory.size();
        
        vector<int> positions;

        for(int i=0;i<m;i++){
            int p=factory[i][0];
            int l=factory[i][1];
            for(int j=0;j<l;j++){
                positions.push_back(p);
            }
        }
        vector<vector<ll>> dp(n+10,vector<ll> (positions.size()+10,-1));

        sort(robot.begin(),robot.end());
        sort(positions.begin(),positions.end());

        return f(0,0,n,positions.size(),robot,positions,dp);
        
    }
};