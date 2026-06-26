class Solution {
public:
    typedef long long int ll;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> adj(26,vector<ll>(26,INT_MAX));
        for(int i=0;i<26;i++){
            adj[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            adj[u][v]=min((ll)adj[u][v],(ll)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX){
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0;i<source.size();i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(adj[u][v]==INT_MAX){
                return -1;
            }
            ans+=adj[u][v];
        }
        return ans;
    }
};