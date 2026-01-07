class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int n,vector<int>& nums,vector<int>& temp,set<int> &s){

        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        

        for(int i=0;i<n;i++){
            if(s.find(nums[i])==s.end()){
                temp.push_back(nums[i]);
                s.insert(nums[i]);
                f(0,n,nums,temp,s);
                s.erase(nums[i]);
                temp.pop_back();
            }
            

        }


    }
    vector<vector<int>> permute(vector<int>& nums) {

        int n=nums.size();
        set<int> s;
        vector<int> temp;
        f(0,n,nums,temp,s);
        return ans;

        
    }
};