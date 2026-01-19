class Solution {
public:
    typedef long long int ll;
    vector<int> singleNumber(vector<int>& nums) {

        ll n=nums.size();
        ll total_xor=0;
        for(ll i=0;i<n;i++){
            total_xor^=nums[i];
        }

        ll n1=0,n2=0;
        ll mask=total_xor & (-total_xor);

        for(auto &x:nums){
            if(mask & x){
                n1^=x;
            }
            else n2^=x;
        }

        return {(int)n1,(int)n2};
        
    }
};