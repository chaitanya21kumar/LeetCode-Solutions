class Solution {
public:
    typedef long long int ll;
    int minOperations(vector<int>& nums, int k) {

        ll ops=0;
        ll n=nums.size();
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(pq.size()>=2 && pq.top()<k){
            ll x=pq.top();
            pq.pop();
            ll y=pq.top();
            pq.pop();
            ll e=(min(x,y)*2 + max(x,y));
            pq.push(e);
            ops++;
        }
        return ops;
        
    }
};