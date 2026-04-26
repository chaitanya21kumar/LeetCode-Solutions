class Solution {
public:
    int dp[1010];
    int f(int i,int n,vector<vector<int>>& books,int sw){

        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        int cw=0;
        int mx=INT_MIN;
        for(int j=i;j<n;j++){
            int t=books[j][0],h=books[j][1];
            if(cw+t<=sw){
                mx=max(mx,h);
                ans=min(ans,mx+f(j+1,n,books,sw));
                cw+=t;
            }
            else{
                ans=min(ans,mx+f(j,n,books,sw));
                break;
            }
        }

        return dp[i]=ans;

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        int n=books.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n,books,shelfWidth);
        
    }
};