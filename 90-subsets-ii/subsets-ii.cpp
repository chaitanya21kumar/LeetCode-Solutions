class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int n,vector<int>& nums,vector<int>& temp){
        ans.push_back(temp);

        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            f(j+1,n,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n=nums.size();
        vector<int> temp;
        sort(nums.begin(),nums.end());
        f(0,n,nums,temp);

        return ans;

    }
};