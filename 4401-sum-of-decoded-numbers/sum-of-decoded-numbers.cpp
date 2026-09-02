class Solution {
public:
    typedef long long int ll;
    #define M 1000000007
    ll f(ll b,ll e){
        ll ans=1;
        while(e>0){
            if(e%2==1){
                ans=(ans*b)%M;
            }
            b=(b*b)%M;
            e/=2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {

        ll n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            ll w=nums[i]%10;
            ll di=nums[i]/10;
            string ds=to_string(di);
            string xs=ds.substr(0,w);
            string ys=ds.substr(w);
            ll x=stoll(xs);
            ll y=stoll(ys);
            ans=(ans+f(x,y))%M;
        }
        return ans;

    }
};