class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        typedef long long int ll;
        ll n=nums.size();
        ll tc=0; // total xor
        for(int i=0;i<n;i++) tc^=nums[i];

        ll m=1;
        while((m & tc)==0) m=m<<1;

        int n1=0,n2=0;

        for(auto &x:nums){
            if((x & m)) n1^=x;
            else n2^=x;
        } 

        return {n1,n2};
        
    }
};