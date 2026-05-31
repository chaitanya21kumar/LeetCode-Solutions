class Solution {
public:
    int f1(int ri,int ki,int n){

        int ans=INT_MAX;
        int ans1=abs(ri-ki);
        int ans2=n-ans1;
        return ans=min(ans1,ans2);

    }
    int f(int ri,int ki,int n,string &ring, string &key,vector<vector<int>> &dp){
        if(ki>=n) return 0;
        if(dp[ri][ki]!=-1) return dp[ri][ki];
        int ans=INT_MAX;
        for(int i=0;i<ring.length();i++){
            if(ring[i]==key[ki]){
                int temp=f1(ri,i,ring.length())+f(i,ki+1,n,ring,key,dp)+1;
                ans=min(ans,temp);
            }
        }
        return dp[ri][ki]=ans;
    }
    int findRotateSteps(string ring, string key) {

        int n=key.length();
        vector<vector<int>> dp(ring.length()+10,vector<int> (n+10,-1));
        return f(0,0,n,ring,key,dp);
        
    }
};