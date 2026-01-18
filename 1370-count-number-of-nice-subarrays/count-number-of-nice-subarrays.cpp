class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n=nums.size();
        int oc=0,ans=0,l=0,r=0;
        int prevc=0;

        while(r<n){
            if(nums[r]%2!=0){
                oc++;
                prevc=0;
            }
            while(l<=r && oc==k){
                prevc++;
                if(nums[l]%2!=0){
                    oc--;
                }
                l++;
            }
            ans+=prevc;
            r++;
        }
        return ans;
        
    }
};