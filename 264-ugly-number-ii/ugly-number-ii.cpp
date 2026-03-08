class Solution {
public:
    typedef long long int ll;
    int nthUglyNumber(int n) {

        priority_queue<ll,vector<ll>,greater<ll>> pq;
        vector<ll> mul={2,3,5};
        unordered_set<ll> s;

        ll cu=1;
        pq.push(1);

        for(int i=0;i<n-1;i++){
            auto x=pq.top();
            pq.pop();

            for(auto &y:mul){
                ll z=x*y;
                if(s.find(z)==s.end()){
                    pq.push(z);
                    s.insert(z);
                }
            }
        }
        return pq.top();

        

        
        
    }
};