class Solution {
public:
    typedef long long int ll;
    typedef pair<int,int> p;
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        int n=boxTypes.size();
        priority_queue<p> pq;
        for(int i=0;i<n;i++){
            int nob=boxTypes[i][0];
            int nou=boxTypes[i][1];
            pq.push({nou,nob});
        }
        int c=truckSize,ans=0;
        while(c>0 && !pq.empty()){
            auto x=pq.top();
            pq.pop();
            int nou=x.first;
            int nob=x.second;
            int mn=min(truckSize,nob);
            ans+=(mn*nou);
            truckSize-=mn;
        }
        return ans;
        
    }
};