class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int d=1,ans=0;
        int i=0;
        while(i<n || !pq.empty()){
            if(pq.empty()) d=max(d,events[i][0]);
            while(i<n && events[i][0]==d){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && d>pq.top()) pq.pop();
            if(!pq.empty()){
                pq.pop();
                d++;
                ans++;
            }
        }
        return ans;
    }
};