class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n+1,0);
        for(auto &x:trust){
            int u=x[0];
            int v=x[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1 && adj[i].size()==0){ 
                return i;
            }
        }
        return -1;
        
    }
};