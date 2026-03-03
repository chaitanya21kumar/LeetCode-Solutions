class Solution {
public:
    typedef long long int ll;
    typedef pair<ll,ll> p;
    long long minimumCost(vector<int>& nums, int k, int dist) {

        ll n=nums.size();
        set<p> kmn;
        set<p> rem;
        ll s=0;
        int i=1;
        ll ans=LLONG_MAX;
        while(i-dist<1){
            kmn.insert({nums[i],i});
            s+=nums[i];
            if(kmn.size()>k-1){
                auto x=*kmn.rbegin();
                s-=x.first;
                kmn.erase(x);
                rem.insert(x);
            }
            i++;
        }
        while(i<n){
            s+=nums[i];
            kmn.insert({nums[i],i});

            if(kmn.size()>k-1){
                auto x=*kmn.rbegin();
                s-=x.first;
                kmn.erase(x);
                rem.insert(x);
            }

            ans=min(ans,s);
            p y={nums[i-dist],i-dist};
            if(kmn.count(y)){
                kmn.erase(y);
                s-=y.first;

                if(!rem.empty()){
                    auto z=*rem.begin();
                    kmn.insert(z);
                    s+=z.first;
                    rem.erase(z);
                }
            }
            else{
                rem.erase(y);
            }

            i++;
        }
        return nums[0]+ans;


        
    }
};