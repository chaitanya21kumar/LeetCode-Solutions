class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n=nums.size();
        int i=0;
        int j=0;
        int m=0;
        int ans=1;
        while(j<n){
            while((m&nums[j])!=0){
                m=m^nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
            m=m|nums[j];
            j++;
        }
        return ans;
        
    }
};