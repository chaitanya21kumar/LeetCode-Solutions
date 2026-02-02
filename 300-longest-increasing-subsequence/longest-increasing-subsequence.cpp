class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<int> lis;
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=lower_bound(lis.begin(),lis.end(),nums[i]);
            if(it==lis.end()){
                lis.push_back(nums[i]);
            }
            else{
                int idx=it-lis.begin();
                lis[idx]=nums[i];
            }
            ans=max(ans,(int)(lis.size()));
        }
        return ans;

        
    }
};