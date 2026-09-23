class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int n=nums.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &x:m){
            auto v=x.second;
            if(v.size()==3 && v[1]-v[0]==v[2]-v[1]) ans++;
        }
        return ans;
        
    }
};