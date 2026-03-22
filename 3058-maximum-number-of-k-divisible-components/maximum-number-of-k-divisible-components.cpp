class Solution {
public:
    int c=0;
    unordered_map<int,vector<int>> adj;
    int f(int curr,int par,vector<int>& values,int k){
        int sum=values[curr];
        for(auto &y:adj[curr]){
            if(y==par) continue;
            sum=(sum+f(y,curr,values,k))%k;
        }
        sum%=k;
        if(sum==0) c++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        for(auto &x:edges){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        f(0,-1,values,k);
        return c;
        
    }
};