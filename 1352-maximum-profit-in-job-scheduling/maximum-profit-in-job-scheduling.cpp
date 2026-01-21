class Solution {
public:
    vector<vector<int>> jobs;
    int dp[50010];
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[0]<b[0];
    }
    int f1(int i,int end,int n){
        int l=i,r=n-1;
        int ans=n;
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(jobs[mid][0]>=end){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    int f(int i,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=0,nottake=0;
        int next=f1(i+1,jobs[i][1],n);
        take=jobs[i][2]+f(next,n);
        nottake=f(i+1,n);
        return dp[i]=max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n=startTime.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),comp);
        return f(0,n);
    }
};