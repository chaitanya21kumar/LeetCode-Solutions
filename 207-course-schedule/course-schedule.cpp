class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        queue<int> q;
        for(auto &x:prerequisites){
            int u=x[1];
            int v=x[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                ans.push_back(x);
                for(auto &v:adj[x]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        q.push(v);
                    }
                }
            }
        }
        if(ans.size()==n) return true;
        return false;
        
    }
};