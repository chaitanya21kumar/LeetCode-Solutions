class Solution {
public:
    #define M 1000000007
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        int n=nums.size();
        vector<int> f(n+1,0);
        for(auto &x:requests){
            int s=x[0];
            int e=x[1];
            f[s]++;
            f[e+1]--;
        }

        f.pop_back();
        for(int i=1;i<n;i++){
            f[i]+=f[i-1];
        }
        sort(nums.begin(),nums.end());
        sort(f.begin(),f.end());
        long long int ans=0;
        for(int i=0;i<n;i++){
            if(f[i]>0){
                ans=(ans+(1LL)*f[i]*nums[i])%M;
            }
        }
        return (int)ans;
        
        
    }
};