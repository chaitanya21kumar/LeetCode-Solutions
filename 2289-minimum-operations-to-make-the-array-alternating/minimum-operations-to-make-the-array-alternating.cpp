class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int n=nums.size();
        vector<pair<int,int>> o,e; // {f,val}
        map<int,int> mo,me;
        for(int i=0;i<n;i++){
            if(i%2==0){
                me[nums[i]]++;
            }
            else{
                mo[nums[i]]++;
            }
        }
        for(auto &x:me) e.push_back({x.second,x.first});
        for(auto &y:mo) o.push_back({y.second,y.first});
        sort(e.rbegin(),e.rend());
        sort(o.rbegin(),o.rend());
        e.push_back({0,0});
        o.push_back({0,0});

        int mfev=e[0].second; // most freq even val
        int mfef=e[0].first; // most freq even freq
        int mfov=o[0].second;
        int mfof=o[0].first;
        if(mfev!=mfov) return n-(mfef+mfof);
        else{
            int sfev=e[1].second;
            int sfef=e[1].first;
            int sfov=o[1].second;
            int sfof=o[1].first;
            int c1=mfef+sfof;
            int c2=sfef+mfof;
            int c=max(c1,c2);
            return n-c;
        }
        return 0;
        
    }
};