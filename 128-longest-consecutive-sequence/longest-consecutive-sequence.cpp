class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++) s.insert(nums[i]);
        int ans=0;
        for(auto x:s){
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