class Solution {
public:
    typedef long long int ll;
    typedef pair<ll,ll> p;
    long long findScore(vector<int>& nums) {

        ll n=nums.size();
        unordered_set<ll> s;
        priority_queue<p,vector<p>,greater<p>> pq;
        ll ans=0;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(!pq.empty()){
            auto x=pq.top();
            ll idx=x.second;
            ll val=x.first;
            pq.pop();
            if(s.find(idx)==s.end()){
                ans+=val;
                s.insert(idx);
                if(idx-1>=0) s.insert(idx-1);
                if(idx+1<n) s.insert(idx+1);
            }
        }
        return ans;
        
    }
};