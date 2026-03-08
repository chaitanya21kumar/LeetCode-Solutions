class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,pair<int,int>>> q;
        int sr=entrance[0];
        int sc=entrance[1];
        q.push({0,{sr,sc}});
        int s=0;
        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> vis(m,vector<int> (n,0));
        vis[sr][sc]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                int s=x.first;
                int ri=x.second.first;
                int ci=x.second.second;
                if( (ri==0 || ri==m-1 || ci==0 || ci==n-1) && s!=0 ) return s;
                for(auto &y:dirs){
                    int r=ri+y[0];
                    int c=ci+y[1];
                    if(r>=0 && r<m && c>=0 && c<n && maze[r][c]=='.' && !vis[r][c]){
                        vis[r][c]=1;
                        q.push({s+1,{r,c}});
                    }
                }
            }
        }
        return -1;
        
    }
};