class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n=rooms.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        for(int i=0;i<n;i++){
            int u=i;
            for(auto &x:rooms[i]){
                if(i!=x){
                    int v=x;
                    adj[u].push_back(v);
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                for(auto &y:adj[x]){
                    if(!vis[y]){
                        vis[y]=1;
                        q.push(y);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;

        
    }
};