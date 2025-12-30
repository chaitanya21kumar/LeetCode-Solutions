class Solution {
public:
    set<vector<int>> s;
    void f(int i,int n,int t,vector<int>& nums,vector<int> &temp){
        if(t==0){
            s.insert(temp);
            return;
        }
        if(i>=n) return;
        if(nums[i]<=t){
            temp.push_back(nums[i]);
            f(i+1,n,t-nums[i],nums,temp);
            f(i,n,t-nums[i],nums,temp);
            temp.pop_back();
            f(i+1,n,t,nums,temp);
        }
        else{
            f(i+1,n,t,nums,temp);
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n=candidates.size();
        vector<int> temp;
        f(0,n,target,candidates,temp);

        vector<vector<int>> ans;
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;


        
    }
};