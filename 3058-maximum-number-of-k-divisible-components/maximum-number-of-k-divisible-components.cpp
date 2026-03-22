class Solution {
public:
    int count=0;
    int f(int curr,int par,vector<int>& values,int k,vector<vector<int>> &adj){
        int sum=values[curr];
        for(auto &y:adj[curr]){
            if(y==par) continue;
            sum=(sum+f(y,curr,values,k,adj))%k;
        }
        sum%=k;
        if(sum==0) count++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector<vector<int>> adj(n);
        for(auto &x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        f(0,-1,values,k,adj);
        return count;
        
    }
};