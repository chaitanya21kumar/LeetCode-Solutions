class Solution {
public:
    typedef long long int ll;
    long long minimumDifference(vector<int>& nums) {

        ll N=nums.size();
        ll n=N/3;
        vector<ll> vls(N,0),vrs(N,0);
        priority_queue<ll> pqls;
        priority_queue<ll,vector<ll>,greater<ll>> pqrs;
        ll ls=0,rs=0;
        for(int i=0;i<=2*n-1;i++){
            pqls.push(nums[i]);
            ls+=nums[i];
            if(pqls.size()>n){
                ls-=pqls.top();
                pqls.pop();
            }
            vls[i]=ls;
        }
        for(int i=N-1;i>=n;i--){
            pqrs.push(nums[i]);
            rs+=nums[i];
            if(pqrs.size()>n){
                rs-=pqrs.top();
                pqrs.pop();
            }
            vrs[i]=rs;
        }
        ll ans=LLONG_MAX;
        for(int i=n-1;i<=2*n-1;i++){
            ans=min(ans,vls[i]-vrs[i+1]);
        }
        return ans;
    }
};