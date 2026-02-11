class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {

        int r=heights.size(),c=heights[0].size();
        vector<vector<int>> dist(r,vector<int> (c,1e8));
        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        dist[0][0]=0;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int e=x.first;
            int rr=x.second.first;
            int cc=x.second.second;
            if(rr==r-1 && cc==c-1) return e;
            if(e>dist[rr][cc]) continue;
            for(auto &dir:dirs){
                int ri=rr+dir[0],ci=cc+dir[1];
                if(ri>=0 && ri<r && ci>=0 && ci<c){
                    int ce=abs(heights[rr][cc]-heights[ri][ci]);
                    int ne=max(ce,e);
                    if(dist[ri][ci]>ne){
                        dist[ri][ci]=ne;
                        pq.push({ne,{ri,ci}});
                    }
                }
            }
        }
        return 0;

        
        
    }
};