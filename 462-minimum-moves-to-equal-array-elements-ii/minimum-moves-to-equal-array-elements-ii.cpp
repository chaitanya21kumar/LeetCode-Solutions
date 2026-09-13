class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=-1;
        int x=n/2;
        if(n%2==0){
            mid=(nums[x]+nums[x-1])/2;
        }
        else{
            mid=nums[x];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-mid);
        }
        return ans;
        
    }
};