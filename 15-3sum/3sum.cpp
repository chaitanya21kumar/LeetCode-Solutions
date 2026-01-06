class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(l<r && r<n){
                int s=nums[i]+nums[l]+nums[r];
                if(s>0) r--;
                else if(s<0) l++;
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    while(l<r && nums[l]==nums[l-1]) l++;
                }
            }
        }
        return ans;
        // -4 -1 -1 0 1 2 
        
    }
};