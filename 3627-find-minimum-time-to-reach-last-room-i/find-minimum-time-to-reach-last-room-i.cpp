class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>> v(n,vector<int> (m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        v[0][0]=0;
        pq.push({0,0,0});

        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};

        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int ct=x[0],r=x[1],c=x[2];

            if(ct>v[r][c]) continue;
            if(r==n-1 && c==m-1) return ct;

            for(auto &x:dirs){
                int ri=r+x[0],ci=c+x[1];

                if(ri>=0 && ri<n && ci>=0 && ci<m){
                    int x=max(moveTime[ri][ci],ct);
                    int nt=x+1;
                    if(nt<v[ri][ci]){
                        v[ri][ci]=nt;
                        pq.push({nt,ri,ci});
                    }
                }
            }



        }

        return -1;
        
    }
};