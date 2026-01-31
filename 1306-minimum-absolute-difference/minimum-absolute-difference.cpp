class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n=nums.size();
        int mndf=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            mndf=min(mndf,nums[i+1]-nums[i]);
        }
        int c=0;
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if((nums[i+1]-nums[i])==mndf) ans.push_back({nums[i],nums[i+1]});
        }
        return ans;
    }
};