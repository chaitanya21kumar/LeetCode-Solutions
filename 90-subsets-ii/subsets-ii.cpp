class Solution {
public:
    set<vector<int>> s;
    void f(int i,int n,vector<int>& nums,vector<int> &temp){
        if(i>=n){
            s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        f(i+1,n,nums,temp);
        temp.pop_back();
        f(i+1,n,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n=nums.size();
        vector<int> temp;
        sort(nums.begin(),nums.end());
        f(0,n,nums,temp);
        vector<vector<int>> ans;
        for(auto x:s){
            ans.push_back(x);
        }

        return ans;

        
    }
};