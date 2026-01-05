class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        unordered_map<int,int> m;

        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            if(m.find(t-nums[i])!=m.end() && m[t-nums[i]]!=i){
                return {m[t-nums[i]],i};
            }
        }

        return {};

        


        
    }
};