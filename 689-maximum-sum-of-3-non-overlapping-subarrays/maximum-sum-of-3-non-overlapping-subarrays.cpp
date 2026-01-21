class Solution {
public:
    vector<int> ans;
    vector<int> pref;
    int dp[20010][5];
    int f1(int i,int c,int k,int n){
        if(c==0) return 0;
        if(i>=n) return INT_MIN;
        if(dp[i][c]!=-1) return dp[i][c];
        int l=i,r=i+k-1,sum=0;
        if(r<n){
            sum=pref[r]-(l>0?pref[l-1]:0);
        }
        int take=sum+f1(i+k,c-1,k,n);
        int nottake=f1(i+1,c,k,n);
        return dp[i][c]=max(take,nottake);
    }
    int f(int i,int c,int k,int n){
        if(c==0) return 0;
        if(i>=n) return INT_MIN;
        int l=i,r=i+k-1;
        int sum=0;
        if(r<n){
            sum=pref[r]-(l>0?pref[l-1]:0);
        }
        int take=sum+f1(i+k,c-1,k,n);
        int nottake=f1(i+1,c,k,n);
        if(take>=nottake){
            ans.push_back(i);
            f(i+k,c-1,k,n);
        }
        else f(i+1,c,k,n);
        return max(take,nottake);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n=nums.size();
        pref.assign(n+1,0);
        pref[0]=nums[0];
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+nums[i];

        f(0,3,k,n);
        return ans;
    }
};