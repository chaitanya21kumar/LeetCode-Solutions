class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        unordered_set<int> s;
        for(int i=1;i<=nums.size();i++) s.insert(i);
        for(int i=0;i<nums.size();i++){
            s.erase(nums[i]);
        }
        vector<int> v(s.begin(),s.end());
        return v;
    }
};