class Solution {
public:
    typedef long long int ll;
    #define M 1000000007
    int maximumProduct(vector<int>& nums, int k) {

        ll n=nums.size();
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        ll p=1;
        while(k>0 && !pq.empty()){
            auto x=pq.top();
            pq.pop();
            ll ele=x+1;
            pq.push(ele);
            k--;
        }
        while(!pq.empty()){
            ll x=pq.top();
            p = (p*x)%M;
            pq.pop();
        }
        return p%M;

    }
};