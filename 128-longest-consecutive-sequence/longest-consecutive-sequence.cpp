class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();
        int ans=0;
        unordered_set<int> s;
        for(int i=0;i<n;i++) s.insert(nums[i]);
        for(auto &x:s){
            if(s.find(x-1)==s.end()){
                int l=0;
                while(s.find(x+l)!=s.end()){
                    l++;
                    ans=max(ans,l);
                }
            }
        }
        return ans;
        
    }
};