class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        int mx=0;
        vector<int> d(n,0);
        vector<vector<int>> ic(n,vector<int> (n,0));
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            d[u]++;
            d[v]++;
            ic[u][v]=1;
            ic[v][u]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x=d[i]+d[j];
                if(ic[i][j]==1) x--;
                mx=max(mx,x);
            }
        }
        return mx;
        
    }
};