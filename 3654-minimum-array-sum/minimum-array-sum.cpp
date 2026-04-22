class Solution {
public:
    int dp[101][101][101];
    int f(int i,vector<int>& nums,int n,int op1,int op2,int k){
        if(i>=n) return 0;
        if(dp[i][op1][op2]!=-1) return dp[i][op1][op2];

        int v=nums[i];
        int mns=v+f(i+1,nums,n,op1,op2,k);
        if(op1>0){
            if(nums[i]>0){
                int x=ceil(v/2.0);
                mns=min(mns,x+f(i+1,nums,n,op1-1,op2,k));
            }
        }
        if(op2>0){
            if(nums[i]>=k){
                int x=nums[i]-k;
                mns=min(mns,x+f(i+1,nums,n,op1,op2-1,k));
            }
        }
        if(op1>0 && op2>0){
            if(nums[i]>0){
                int x=ceil(nums[i]/2.0);
                if(x>=k){
                    x-=k;
                    mns=min(mns,x+f(i+1,nums,n,op1-1,op2-1,k));
                }
            }
        }
        if(op1>0 && op2>0){
            if(nums[i]>=k){
                int x=nums[i]-k;
                if(x>0){
                    x=ceil(x/2.0);
                    mns=min(mns,x+f(i+1,nums,n,op1-1,op2-1,k));
                }

            }
        }
        return dp[i][op1][op2]=mns;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {

        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(0,nums,n,op1,op2,k);
        
    }
};