class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
        vector<vector<int>> dist(n,vector<int> (n,0));
        vector<vector<int>> vis(n,vector<int> (n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            auto x=q.front();
            int rr=x.first;
            int cc=x.second;
            q.pop();
            for(auto &dir:dirs){
                int r=rr+dir[0],c=cc+dir[1];
                if(r>=0 && r<n && c>=0 && c<n && vis[r][c]==0){
                    vis[r][c]=1;
                    q.push({r,c});
                    dist[r][c]=1+dist[rr][cc];
                }
            }
        }
        priority_queue<p> pq;
        vector<vector<int>> vis2(n,vector<int> (n,0));
        pq.push({dist[0][0],{0,0}});
        vis2[0][0]=1;
        int ans=INT_MAX;
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