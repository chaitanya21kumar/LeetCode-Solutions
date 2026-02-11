class Solution {
public:
    int f(vector<int>& nums, int k,int n){
        int l=0,r=0,ans=0,cd=0;
        unordered_map<int,int> m;
        while(r<n){
            if(m[nums[r]]==0) cd++;
            m[nums[r]]++;
            while(cd>k){
                m[nums[l]]--;
                if(m[nums[l]]==0) cd--;
                l++;
            }
            if(cd<=k) ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int n=nums.size();
        return f(nums,k,n)-f(nums,k-1,n);
        
    }
};