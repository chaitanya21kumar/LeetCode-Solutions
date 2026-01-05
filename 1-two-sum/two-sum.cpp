class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {

        int n=nums.size();
        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
            int x=t-nums[i];
            if(m.find(x)!=m.end()) return {m[x],i};
            m[nums[i]]=i;
        }
        
        return {};
        
    }
};