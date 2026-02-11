class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n=nums.size();
        if(n<3) return 0;
        int ans=0;
        int c=0;
        for(int i=0;i<=n-3;i++){
            int d1=nums[i+1]-nums[i];
            int d2=nums[i+2]-nums[i+1];
            if(d1==d2) c=c+1;
            else c=0;
            ans+=c;
        }
        return ans;
        
    }
};