class Solution {
public:
    int f(int i,int j,int n1,int n2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){

        if(i==n1 || j==n2) return -1e9;
        if(dp[i][j]!=-1) return dp[i][j];

        int p1=nums1[i]*nums2[j];
        int p2=nums1[i]*nums2[j]+f(i+1,j+1,n1,n2,nums1,nums2,dp);
        int p3=f(i,j+1,n1,n2,nums1,nums2,dp);
        int p4=f(i+1,j,n1,n2,nums1,nums2,dp);

        return dp[i][j]=max({p1,p2,p3,p4});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();

        vector<vector<int>> dp(n1+10,vector<int> (n2+10,-1));
        return f(0,0,n1,n2,nums1,nums2,dp);
        
    }
};