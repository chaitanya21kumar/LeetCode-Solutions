class Solution {
public:
    typedef long long int ll;
    int totalHammingDistance(vector<int>& nums) {

        int n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int xori= (nums[i] ^ nums[j]);
                ans+=(__builtin_popcount(xori));
            }
        }
        return ans;
        
    }
};