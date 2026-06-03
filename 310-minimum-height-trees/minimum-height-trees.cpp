class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<int> ind(n);
        vector<int> ans;
        if(n<=2){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(auto &x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ind[u]++;
            ind[v]++;
        }
        int rn=n;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==1){
                q.push(i);
            } 
        }
        while(rn>2){
            int x=q.size();
            rn-=x;
            for(int i=0;i<x;i++){
                int node=q.front();
                q.pop();
                for(auto &y:adj[node]){
                    ind[y]--;
                    if(ind[y]==1){
                        q.push(y);
                    }
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};