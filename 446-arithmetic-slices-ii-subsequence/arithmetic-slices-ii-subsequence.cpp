class Solution {
public:
    typedef long long int ll;
    int numberOfArithmeticSlices(vector<int>& nums) {

        ll n=nums.size();
        ll ans=0;
        unordered_map<ll,ll> arr[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff=(ll)nums[j]-nums[i];
                auto it=arr[j].find(diff);
                ll cj=(it==arr[j].end())?0:it->second;
                arr[i][diff]+=cj+1;
                ans+=cj;
            }
        }
        return ans;

        
    }
};