class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int x=target-nums[i];
            if(m.find(x)!=m.end() && i!=m[x]){
                ans.push_back(i);
                ans.push_back(m[x]);
                break;
            }
        }
        return ans;
        
    }
};