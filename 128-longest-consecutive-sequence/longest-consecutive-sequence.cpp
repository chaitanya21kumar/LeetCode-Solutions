class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(auto &x:s){
            int num=x;
            if(s.find(num-1)==s.end()){
                int c=1;
                int x=num;
                while(s.find(x+1)!=s.end()){
                    x++;
                    c++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
        
    }
};