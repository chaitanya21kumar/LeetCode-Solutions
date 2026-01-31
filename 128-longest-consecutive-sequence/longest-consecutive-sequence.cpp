class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int l=nums[0];
        int ans=0,c=1;
        for(int i=0;i<n;i++){
            if(nums[i]==l+1){
                c++; 
            }
            else if(nums[i]!=l){
                c=1;
            }
            l=nums[i];
            ans=max(ans,c);
        }
        return ans;
        // 0 1 1 2
        
    }
};