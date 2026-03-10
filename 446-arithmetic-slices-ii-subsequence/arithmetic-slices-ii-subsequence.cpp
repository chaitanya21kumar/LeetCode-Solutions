class Solution {
public:
    typedef long long int ll;
    int numberOfArithmeticSlices(vector<int>& nums) {

        ll n=nums.size();
        ll ans=0;
        unordered_map<ll,ll> arr[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                auto diff=(ll)nums[j]-(ll)nums[i];
                auto it=arr[j].find(diff);
                ll cj=(it==arr[j].end())?0:it->second;
                ans+=cj;
                arr[i][diff]+=cj+1;
            }
        }
        return ans;
        
    }
};