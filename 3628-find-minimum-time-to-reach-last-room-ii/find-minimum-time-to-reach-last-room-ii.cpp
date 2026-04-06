class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {


        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        vector<vector<int>> v(n,vector<int> (m,INT_MAX));
        v[0][0]=0;
        pq.push({0,0,0}); // time,r,c

        while(!pq.empty()){

            auto x=pq.top();
            pq.pop();
            int ct=x[0];
            int r=x[1];
            int c=x[2];

            if(ct>v[r][c]) continue;

            if(r==n-1 && c==m-1) return ct;

            int wt=0;
            if((r+c)%2==0) wt=1;
            else wt=2;

            for(auto &x:dirs){
                int ri=x[0],ci=x[1];
                int nr=r+ri;
                int nc=c+ci;

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int z=max(ct,moveTime[nr][nc]);
                    int nt=z+wt;

                    if(nt<v[nr][nc]){
                        v[nr][nc]=nt;
                        pq.push({nt,nr,nc});
                    }

                }

            }

        }

        return -1;
        
    }
};