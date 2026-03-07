class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            auto x=lower_bound(ans.begin(),ans.end(),nums[i]);
            if(x==ans.end()){
                ans.push_back(nums[i]);
            }
            else ans[x-ans.begin()]=nums[i];
        }
        return (int)ans.size();
        
    }
};