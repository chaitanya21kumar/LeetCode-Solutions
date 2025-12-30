class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int n,vector<int>& nums,vector<int> temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        f(i+1,n,nums,temp);
        temp.pop_back();
        f(i+1,n,nums,temp);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();
        vector<int> temp;
        f(0,n,nums,temp);
        return ans;

        
    }
};