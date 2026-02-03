class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n=routes.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            for(auto &x:routes[i]){
                m[x].push_back(i);
            }
        }
        vector<int> vis(n,0);
        int ans=1;
        queue<int> q;
        for(auto &x:m[source]){
            q.push(x);
        }

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int idx=q.front();
                q.pop();
                if(vis[idx]==1) continue;
                vis[idx]=1;
                for(auto &x:routes[idx]){
                    if(x==target) return ans;
                    for(auto &y:m[x]){
                        if(!vis[y]){
                            q.push(y);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;

        
    }
};