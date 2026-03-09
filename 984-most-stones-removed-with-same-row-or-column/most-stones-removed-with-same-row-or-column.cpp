class Solution {
public:
    void dfs(int i,int n,vector<vector<int>>& stones,vector<int> &vis){

        vis[i]=1;
        for(int j=0;j<n;j++){
            if(!vis[j]){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dfs(j,n,stones,vis);
                }
            }
        }

    }
    int removeStones(vector<vector<int>>& stones) {

        int n=stones.size();
        vector<int> vis(n,0);
        int ncc=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ncc++;
                dfs(i,n,stones,vis);
            }
        }
        return n-ncc;
        
    }
};