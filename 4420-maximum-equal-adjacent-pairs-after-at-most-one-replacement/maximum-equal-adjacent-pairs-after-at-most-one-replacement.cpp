class Solution {
public:
    typedef long long int ll;
    int maxEqualAdjacentPairs(vector<int>& nums) {

        int n=nums.size();
        int bp=0;
        int ap=0;
        unordered_map<ll,int> m;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) bp++;
            else{
                ll u=min(nums[i],nums[i+1]);
                ll v=max(nums[i],nums[i+1]);
                ll x=(u<<32)|v;
                m[x]++;
                ap=max((ll)ap,(ll)m[x]);
            }
        }
        return bp+ap;
        
    }
};