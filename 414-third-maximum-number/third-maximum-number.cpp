class Solution {
public:
    int thirdMax(vector<int>& nums) {

        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> v(s.begin(),s.end());
        sort(v.begin(),v.end());
        int n=v.size();

        if(n==1) return v[0];
        if(n==2) return v[1];
        return v[n-3];
        
    }
};