class Solution {
public:
    int f(int ri,int ki,int n){
        int ans=INT_MAX;
        int ans1=abs(ri-ki);
        int ans2=n-ans1;
        return ans=min(ans1,ans2);
    }
    int findRotateSteps(string ring, string key) {

        int nr=ring.length();
        int nk=key.length();

        unordered_map<char,vector<int>> m;
        for(int i=0;i<nr;i++){
            m[ring[i]].push_back(i);
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});

        set<pair<int,int>> st;

        while(!pq.empty()){
            auto x=pq.top();
            int s=x[0];
            int ri=x[1];
            int ki=x[2];
            pq.pop();

            if(st.find({ri,ki})!=st.end()) continue;
            st.insert({ri,ki});
            if(ki>=nk) return s+nk;

            for(auto &y:m[key[ki]]){
                int steps=f(ri,y,nr);
                pq.push({s+steps,y,ki+1,});
            }
        }
        
        return 0;
    }
};