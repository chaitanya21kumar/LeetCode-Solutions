class Solution {
public:
    bool f(vector<int> &v){
        int n=v.size();
        int d=v[1]-v[0];
        for(int i=0;i<n-1;i++){
            if(v[i+1]-v[i]!=d) return false;
        }
        return true;
    }
    int countSpecialIntegers(vector<int>& nums) {

        int n=nums.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &x:m){
            auto v=x.second;
            if(v.size()>=3 && f(v)) ans++;
        }
        return ans;
        
    }
};