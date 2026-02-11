class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<vector<int>> dist(n,vector<int> (n,0));
        vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int rr=x.first;
            int cc=x.second;
            for(auto &dir:dirs){
                int r=rr+dir[0],c=cc+dir[1];
                if(r>=0 && r<n && c>=0 && c<n && vis[r][c]==0){
                    vis[r][c]=1;
                    dist[r][c]=dist[rr][cc]+1;
                    q.push({r,c});
                }
            }
        }
        vector<vector<int>> vis2(n,vector<int> (n,0));
        priority_queue<p> pq;
        pq.push({dist[0][0],{0,0}});
        vis2[0][0]=1;
        int ans=dist[0][0];
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int d=x.first;
            int rr=x.second.first;
            int cc=x.second.second;
            ans=min(ans,d);
            if(rr==n-1 && cc==n-1) return ans;
            for(auto &dir:dirs){
                int r=rr+dir[0],c=cc+dir[1];
                if(r>=0 && r<n && c>=0 && c<n && vis2[r][c]==0){
                    vis2[r][c]=1;
                    pq.push({dist[r][c],{r,c}});
                }
            }
        }
        return 0;

        
        
    }
};