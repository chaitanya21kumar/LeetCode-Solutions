class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<int> indegree(n,0);
        unordered_map<int,vector<int>> adj;
        vector<int> ans=time;
        for(auto &x:relations){
            int u=x[0]-1;
            int v=x[1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
                ans[x]=max(ans[x],ans[node]+time[x]);
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};