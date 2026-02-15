class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto &x:m){
            if(x.second>1){
                int y=x.second;
                ans+=(y*(y-1)/2);
            }
        }
        return ans;
        
    }
};