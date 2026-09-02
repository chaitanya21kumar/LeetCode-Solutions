class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int n=nums.size();
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                m[nums[i]]++;
            }
        }
        for(auto &x:m){
            if(x.second==1){
                ans++;
            }
        }
        return ans;
        
    }
};