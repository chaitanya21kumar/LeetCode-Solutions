class Solution {
public:
    vector<vector<int>> ans;
    set<int> s;
    void f(int i,int n,vector<int>& nums,vector<int> &v){
        if(v.size()==n){
            ans.push_back(v);
            return;
        }

        for(int j=0;j<n;j++){
            if(s.find(nums[j])==s.end()){
                v.push_back(nums[j]);
                s.insert(nums[j]);
                f(0,n,nums,v);
                s.erase(nums[j]);
                v.pop_back();
            }
        }

        

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();

        f(0,n,nums,v);

        return ans;

        
    }
};