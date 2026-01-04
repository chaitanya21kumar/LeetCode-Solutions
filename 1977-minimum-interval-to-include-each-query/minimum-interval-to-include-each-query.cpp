class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        int n=intervals.size();
        int qs=queries.size();

        sort(intervals.begin(),intervals.end());

        vector<pair<int,int>> sq; // sorted queries {val,idx}
        for(int i=0;i<qs;i++) sq.push_back({queries[i],i});

        sort(sq.begin(),sq.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {size,end}

        int i=0;
        vector<int> ans(qs,-1);

        for(auto &x:sq){
            int val=x.first,idx=x.second;

            while(i<n && intervals[i][0]<=val){
                int l=intervals[i][0],r=intervals[i][1];
                pq.push({r-l+1,r});
                i++;
            }

            while(!pq.empty() && pq.top().second<val) pq.pop();

            if(!pq.empty()) ans[idx]=pq.top().first;

        }

        return ans;

    }
};