class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n=nums.size();
        int l=0,r=0,s=0;
        unordered_map<int,int> m;
        int ans=0;
        m[0]=1;
        while(r<n){
            s+=nums[r];
            if(m.count(s-k)){
                ans+=m[s-k];
            }
            m[s]++;
            r++;
        }
        return ans;

    }
};