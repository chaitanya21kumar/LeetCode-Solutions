class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size(), d = 0, ans = 0, i = 0;
        priority_queue<int,vector<int>,greater<int>> pq;

        while(i<n || !pq.empty()){
            if(pq.empty()) d = max(d,events[i][0]);

            while(i<n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top() < d) pq.pop();

            if(!pq.empty()){
                pq.pop();
                ans++;
                d++;
            }
        }
        // return d;
        return ans;

        


    }
};