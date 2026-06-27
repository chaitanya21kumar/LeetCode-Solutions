class Solution {
public:
    typedef long long int ll;
    int numberOfSets(int n, int mxd, vector<vector<int>>& roads) {

        int ans=0;
        for(int s=0;s<(1<<n);s++){
            vector<vector<int>> adj(n,vector<int>(n,INT_MAX));

            for(int i=0;i<n;i++){
                adj[i][i]=0;
            }

            for(auto &x:roads){
                int u=x[0];
                int v=x[1];
                int wt=x[2];
                if( ((s>>u)&1)==1  && ((s>>v)&1)==1 ){
                    adj[u][v]=min(adj[u][v],wt);
                    adj[v][u]=min(adj[v][u],wt);
                }
            }


            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        adj[i][j]=min((ll)adj[i][j],(ll)adj[i][k]+adj[k][j]);
                    }
                }
            }

            bool p=true;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if( ((s>>i)&1)==1 && ((s>>j)&1)==1 && adj[i][j]>mxd){
                        p=false;
                        break;
                    }
                }
            }
            if(p){
                ans++;
            }
        }
        return ans;
        
    }
};