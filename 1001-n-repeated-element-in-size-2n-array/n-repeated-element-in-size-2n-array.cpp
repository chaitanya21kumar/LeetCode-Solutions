class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int N=nums.size();
        unordered_set<int> s;
        for(int i=0;i<N;i++){
            if(s.find(nums[i])!=s.end()){
                return nums[i];
            }
            s.insert(nums[i]);
        }
        return 0;
        
    }
};