class Solution {
public:
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    bool f(int r,int c,int mid,vector<vector<int>>& cells){
        vector<vector<int>> g(r,vector<int> (c,0));

        for(int i=0;i<=mid;i++){
            int ri=cells[i][0]-1;
            int ci=cells[i][1]-1;

            g[ri][ci]=1;
        }

        queue<pair<int,int>> q;
        for(int col=0;col<c;col++){
            if(g[0][col]==0){
                q.push({0,col});
                g[0][col]=-1;
            }
        }

        while(!q.empty()){
            auto x=q.front();
            q.pop();

            int rr=x.first;
            int cc=x.second;
            if(rr==r-1) return true;

            for(auto &y:dirs){
                int nr=rr+y[0];
                int nc=cc+y[1];

                if(nr>=0 && nr<r && nc>=0 && nc<c && g[nr][nc]==0){
                    q.push({nr,nc});
                    g[nr][nc]=-1;
                }
            }

        }

        return false;
    }
    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {

        int lo=0;
        int hi=cells.size()-1;
        int ans=0;

        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(f(r,c,mid,cells)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans+1;

    }
};