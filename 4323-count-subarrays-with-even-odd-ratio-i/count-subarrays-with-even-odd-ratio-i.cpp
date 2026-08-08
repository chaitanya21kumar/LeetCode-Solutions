class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int ce=0;
            int co=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) ce++;
                else co++;
                if(co>0 && ce*b<=co*a) ans++;
            }
        }
        return ans;
        
    }
};