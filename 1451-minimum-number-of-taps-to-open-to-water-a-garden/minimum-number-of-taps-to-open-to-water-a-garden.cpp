class Solution {
public:
    int f(int i,int me,int n,vector<pair<int,int>> &v,map<pair<int,int>,int> &dp){
        if(i>=n+1){
            if(me>=n) return 0;
            return 1e6;
        }

        if(dp.find({i,me})!=dp.end()) return dp[{i,me}];

        if(v[i].first>me) return 1e6;
        int pick=1+f(i+1,max(me,v[i].second),n,v,dp);
        int notpick=f(i+1,me,n,v,dp);

        return dp[{i,me}]=min(pick,notpick);
    }
    int minTaps(int n, vector<int>& ranges) {

        vector<pair<int,int>> v;
        map<pair<int,int>,int> dp;
        for(int i=0;i<ranges.size();i++){
            int s=max(0,i-ranges[i]);
            int e=min(n,i+ranges[i]);
            v.push_back({s,e});
        }
        sort(v.begin(),v.end());
        int ans=f(0,0,n,v,dp);

        if(ans>=1e6) return -1;
        return ans;
        
    }
};